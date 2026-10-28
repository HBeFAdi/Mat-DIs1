#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

#define RESET "\033[0m"
#define RED   "\033[31m"
#define CYAN  "\033[36m"

using namespace std;

int langkah = 0; // nomor langkah penyelesaian (di-reset setiap soal baru)

// Hasil akhir perhitungan disimpan di sini, lalu ditampilkan oleh DuaHimpunan / TigaHimpunan
vector<int> hasil2himpunan (9);
vector<int> hasil3himpunan (15);

// FPB dengan algoritma Euclid: ulangi a = b, b = sisa bagi, sampai b habis
long long fpb(long long a, long long b){
    while (b != 0){
        long long sisa = a % b;
        a = b;
        b = sisa;
    }
    return a;
}

// KPK = (a / FPB) * b
// Memakai long long dan dibatasi 2^31: KPK yang lebih besar dari batas int pasti tidak punya kelipatan
// di rentang soal (akhir <= 2^31 - 1), jadi cukup dianggap 2^31 dan tidak overflow.
long long kpk(long long a, long long b){
    long long hasil = a / fpb(a, b) * b;
    return hasil > 2147483648LL ? 2147483648LL : hasil;
}

long long kpk3(long long a, long long b, long long c){
    return kpk(kpk(a, b), c);
}

// Cek apakah semua nilai sudah diketahui (-1 = belum diketahui).
// Parameter yang tidak diisi bernilai 0, sehingga dianggap sudah diketahui.
bool ada(int a, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int g = 0, int h = 0){
    return a != -1 && b != -1 && c != -1 && d != -1 && e != -1 && f != -1 && g != -1 && h != -1;
}

// Mencetak satu langkah. Setiap bagian |...| pada rumus diganti dengan angka dari daftar "nilai" (berurutan)
void catat(const string& nama, const string& rumus, const vector<int>& nilai, int hasil){
    string subst = "";
    int k = 0;                  // urutan angka yang dipakai berikutnya
    bool dalamNama = false;     // true jika sedang membaca nama di antara dua tanda |
    for (char huruf : rumus){
        if (huruf == '|'){
            if (!dalamNama) subst += to_string(nilai[k++]);   // | pembuka: tulis angkanya
            dalamNama = !dalamNama;                           // pembuka -> penutup, penutup -> pembuka
        }
        else if (!dalamNama) subst += huruf;                  // di luar nama (spasi, +, -): salin apa adanya
    }
    cout << CYAN << ++langkah << ". Mencari " << nama << RESET << endl;
    cout << "   Rumus     : " << nama << " = " << rumus << endl;
    cout << "   Substitusi: " << nama << " = " << subst << " = " << hasil << endl << endl;
}

// Membaca satu angka; mengulang jika input bukan angka atau lebih kecil dari -1
int bacaNilai(const string& prompt){
    int x;
    while (true){
        cout << prompt; cin >> x;
        bool salah = cin.fail() || cin.peek() != '\n' || x < -1;
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!salah) return x;
        cout << "Input tidak valid. Masukkan bilangan bulat >= 0, atau -1 jika tidak diketahui." << endl;
    }
}

void judulSoal(const string& judul){
    system("cls");
    cout << "---------- " << judul << " ----------\n";
    cout << "Isi angka yang diketahui, " << RED << "Tulis -1 Untuk Data yang TIDAK DIKETAHUI!!!\n" << RESET;
}

void tampilkanHasil(const vector<string>& nama, const vector<int>& v){
    if (langkah == 0) cout << "(Tidak ada rumus yang dapat dijalankan dengan data yang diberikan.)\n\n";
    cout << "============== HASIL AKHIR ==============\n";
    for (size_t i = 0; i < nama.size(); i++){
        cout << left << setw(36) << nama[i] << ": ";
        if (v[i] == -1) cout << "Belum dapat ditentukan dengan data yang diberikan!" << endl;
        else cout << v[i] << endl;
    }
    cout << "\nTekan Tombol Apapun Untuk Kembali Ke Main Menu..."; _getch();
}

// ======================= PERHITUNGAN =======================
// v berisi data awal (6 angka pertama = hasil input, sisanya -1).
// Langkah penyelesaian dicetak oleh catat(), hasil akhir disimpan di hasil2himpunan.
void Hitung2Himpunan(vector<int> v){
    vector<int> l(9, 0);
    // Nama pendek untuk setiap isi vector v (referensi), supaya rumus mudah dibaca
    int &N = v[0], &A = v[1], &B = v[2], &AnB = v[3], &AuB = v[4], &AuBc = v[5], &hA = v[6], &hB = v[7], &Xor = v[8];
    langkah = 0;
    // Ulangi sampai tidak ada nilai baru yang berhasil dihitung (v sama dengan l)
    while (v != l){
        l = v;
        if (!ada(N) && ada(AuB, AuBc)){ N = AuB + AuBc; catat("|N|", "|A gabungan B| + |A gabungan B komplemen|", {AuB, AuBc}, N); }
        if (!ada(A) && ada(AuB, AnB, B)){ A = AuB + AnB - B; catat("|A|", "|A gabungan B| + |A irisan B| - |B|", {AuB, AnB, B}, A); }
        if (!ada(B) && ada(AuB, AnB, A)){ B = AuB + AnB - A; catat("|B|", "|A gabungan B| + |A irisan B| - |A|", {AuB, AnB, A}, B); }
        if (!ada(AnB) && ada(A, B, AuB)){ AnB = A + B - AuB; catat("|A irisan B|", "|A| + |B| - |A gabungan B|", {A, B, AuB}, AnB); }
        if (!ada(AuB)){
            if (ada(A, B, AnB)){ AuB = A + B - AnB; catat("|A gabungan B|", "|A| + |B| - |A irisan B|", {A, B, AnB}, AuB); }
            else if (ada(N, AuBc)){ AuB = N - AuBc; catat("|A gabungan B|", "|N| - |A gabungan B komplemen|", {N, AuBc}, AuB); }
        }
        if (!ada(AuBc) && ada(N, AuB)){ AuBc = N - AuB; catat("|A gabungan B komplemen|", "|N| - |A gabungan B|", {N, AuB}, AuBc); }
        if (!ada(hA)){
            if (ada(A, AnB)){ hA = A - AnB; catat("|Hanya A|", "|A| - |A irisan B|", {A, AnB}, hA); }
            else if (ada(AuB, B)){ hA = AuB - B; catat("|Hanya A|", "|A gabungan B| - |B|", {AuB, B}, hA); }
        }
        if (!ada(hB)){
            if (ada(B, AnB)){ hB = B - AnB; catat("|Hanya B|", "|B| - |A irisan B|", {B, AnB}, hB); }
            else if (ada(AuB, A)){ hB = AuB - A; catat("|Hanya B|", "|A gabungan B| - |A|", {AuB, A}, hB); }
        }
        if (!ada(Xor)){
            if (ada(hA, hB)){ Xor = hA + hB; catat("|A Xor B|", "|Hanya A| + |Hanya B|", {hA, hB}, Xor); }
            else if (ada(AuB, AnB)){ Xor = AuB - AnB; catat("|A Xor B|", "|A gabungan B| - |A irisan B|", {AuB, AnB}, Xor); }
        }
    }
    hasil2himpunan = v;   // simpan hasil akhir
}

// v berisi data awal (10 angka pertama = hasil input, sisanya -1).
// Hasil akhir disimpan di hasil3himpunan.
void Hitung3Himpunan(vector<int> v){
    vector<int> l(15, 0);
    int &N = v[0], &A = v[1], &B = v[2], &C = v[3], &AnB = v[4], &AnC = v[5], &BnC = v[6], &AnBnC = v[7];
    int &AuBuC = v[8], &AuBuCc = v[9], &hA = v[10], &hB = v[11], &hC = v[12], &tpt2 = v[13], &tpt1 = v[14];
    langkah = 0;
    while (v != l){
        l = v;
        if (!ada(N) && ada(AuBuC, AuBuCc)){ N = AuBuC + AuBuCc; catat("|N|", "|A gabungan B gabungan C| + |A gabungan B gabungan C komplemen|", {AuBuC, AuBuCc}, N); }
        if (!ada(A) && ada(AuBuC, B, C, AnB, AnC, BnC, AnBnC)){
            A = AuBuC - B - C + AnB + AnC + BnC - AnBnC;
            catat("|A|", "|A gabungan B gabungan C| - |B| - |C| + |A irisan B| + |A irisan C| + |B irisan C| - |A irisan B irisan C|", {AuBuC, B, C, AnB, AnC, BnC, AnBnC}, A);
        }
        if (!ada(B) && ada(AuBuC, A, C, AnB, AnC, BnC, AnBnC)){
            B = AuBuC - A - C + AnB + AnC + BnC - AnBnC;
            catat("|B|", "|A gabungan B gabungan C| - |A| - |C| + |A irisan B| + |A irisan C| + |B irisan C| - |A irisan B irisan C|", {AuBuC, A, C, AnB, AnC, BnC, AnBnC}, B);
        }
        if (!ada(C) && ada(AuBuC, A, B, AnB, AnC, BnC, AnBnC)){
            C = AuBuC - A - B + AnB + AnC + BnC - AnBnC;
            catat("|C|", "|A gabungan B gabungan C| - |A| - |B| + |A irisan B| + |A irisan C| + |B irisan C| - |A irisan B irisan C|", {AuBuC, A, B, AnB, AnC, BnC, AnBnC}, C);
        }
        if (!ada(AnB) && ada(AuBuC, A, B, C, AnC, BnC, AnBnC)){
            AnB = A + B + C - AnC - BnC + AnBnC - AuBuC;
            catat("|A irisan B|", "|A| + |B| + |C| - |A irisan C| - |B irisan C| + |A irisan B irisan C| - |A gabungan B gabungan C|", {A, B, C, AnC, BnC, AnBnC, AuBuC}, AnB);
        }
        if (!ada(AnC) && ada(AuBuC, A, B, C, AnB, BnC, AnBnC)){
            AnC = A + B + C - AnB - BnC + AnBnC - AuBuC;
            catat("|A irisan C|", "|A| + |B| + |C| - |A irisan B| - |B irisan C| + |A irisan B irisan C| - |A gabungan B gabungan C|", {A, B, C, AnB, BnC, AnBnC, AuBuC}, AnC);
        }
        if (!ada(BnC) && ada(AuBuC, A, B, C, AnB, AnC, AnBnC)){
            BnC = A + B + C - AnB - AnC + AnBnC - AuBuC;
            catat("|B irisan C|", "|A| + |B| + |C| - |A irisan B| - |A irisan C| + |A irisan B irisan C| - |A gabungan B gabungan C|", {A, B, C, AnB, AnC, AnBnC, AuBuC}, BnC);
        }
        if (!ada(AnBnC) && ada(AuBuC, A, B, C, AnB, AnC, BnC)){
            AnBnC = AuBuC - A - B - C + AnB + AnC + BnC;
            catat("|A irisan B irisan C|", "|A gabungan B gabungan C| - |A| - |B| - |C| + |A irisan B| + |A irisan C| + |B irisan C|", {AuBuC, A, B, C, AnB, AnC, BnC}, AnBnC);
        }
        if (!ada(AuBuC)){
            if (ada(A, B, C, AnB, AnC, BnC, AnBnC)){
                AuBuC = A + B + C - AnB - AnC - BnC + AnBnC;
                catat("|A gabungan B gabungan C|", "|A| + |B| + |C| - |A irisan B| - |A irisan C| - |B irisan C| + |A irisan B irisan C|", {A, B, C, AnB, AnC, BnC, AnBnC}, AuBuC);
            }
            else if (ada(N, AuBuCc)){ AuBuC = N - AuBuCc; catat("|A gabungan B gabungan C|", "|N| - |A gabungan B gabungan C komplemen|", {N, AuBuCc}, AuBuC); }
        }
        if (!ada(AuBuCc) && ada(N, AuBuC)){ AuBuCc = N - AuBuC; catat("|A gabungan B gabungan C komplemen|", "|N| - |A gabungan B gabungan C|", {N, AuBuC}, AuBuCc); }
        if (!ada(hA)){
            if (ada(A, AnB, AnC, AnBnC)){ hA = A - AnB - AnC + AnBnC; catat("|Hanya A|", "|A| - |A irisan B| - |A irisan C| + |A irisan B irisan C|", {A, AnB, AnC, AnBnC}, hA); }
            else if (ada(AuBuC, B, C, BnC)){ hA = AuBuC - B - C + BnC; catat("|Hanya A|", "|A gabungan B gabungan C| - |B| - |C| + |B irisan C|", {AuBuC, B, C, BnC}, hA); }
        }
        if (!ada(hB)){
            if (ada(B, AnB, BnC, AnBnC)){ hB = B - AnB - BnC + AnBnC; catat("|Hanya B|", "|B| - |A irisan B| - |B irisan C| + |A irisan B irisan C|", {B, AnB, BnC, AnBnC}, hB); }
            else if (ada(AuBuC, A, C, AnC)){ hB = AuBuC - A - C + AnC; catat("|Hanya B|", "|A gabungan B gabungan C| - |A| - |C| + |A irisan C|", {AuBuC, A, C, AnC}, hB); }
        }
        if (!ada(hC)){
            if (ada(C, AnC, BnC, AnBnC)){ hC = C - AnC - BnC + AnBnC; catat("|Hanya C|", "|C| - |A irisan C| - |B irisan C| + |A irisan B irisan C|", {C, AnC, BnC, AnBnC}, hC); }
            else if (ada(AuBuC, A, B, AnB)){ hC = AuBuC - A - B + AnB; catat("|Hanya C|", "|A gabungan B gabungan C| - |A| - |B| + |A irisan B|", {AuBuC, A, B, AnB}, hC); }
        }
        if (!ada(tpt2)){
            if (ada(AnB, AnC, BnC, AnBnC)){ tpt2 = AnB + AnC + BnC - 3 * AnBnC;
                catat("Jumlah Tepat 2 Himpunan", "|A irisan B| + |A irisan C| + |B irisan C| - 3 * |A irisan B irisan C|", {AnB, AnC, BnC, AnBnC}, tpt2);
            } else if (ada(AuBuC, tpt1, AnBnC)){ tpt2 = AuBuC - tpt1 - AnBnC;
                catat("Jumlah Tepat 2 Himpunan", "|A gabungan B gabungan C| - |Jumlah Tepat 1 Himpunan| - |A irisan B irisan C|", {AuBuC, tpt1, AnBnC}, tpt2);}
        }
        if (!ada(tpt1)){
            if (ada(hA, hB, hC)){ tpt1 = hA + hB + hC; catat("Jumlah Tepat 1 Himpunan", "|Hanya A| + |Hanya B| + |Hanya C|", {hA, hB, hC}, tpt1); }
            else if (ada(AuBuC, A, B, C, AnBnC)){ tpt1 = 2 * AuBuC - (A + B + C) + AnBnC;
                catat("Jumlah Tepat 1 Himpunan", "2 * |A gabungan B gabungan C| - (|A| + |B| + |C|) + |A irisan B irisan C|", {AuBuC, A, B, C, AnBnC}, tpt1); }
            else if (ada(AuBuC, AnB, AnC, BnC, AnBnC)){ tpt1 = AuBuC - AnB - AnC - BnC + 2 * AnBnC;
                catat("Jumlah Tepat 1 Himpunan", "|A gabungan B gabungan C| - (|A irisan B| + |A irisan C| + |B irisan C|) + 2 * |A irisan B irisan C|", {AuBuC, AnB, AnC, BnC, AnBnC}, tpt1); }
        }
    }
    hasil3himpunan = v;   // simpan hasil akhir
}

// ======================= INPUT DAN OUTPUT =======================
void DuaHimpunan(){
    vector<int> v(9, -1);
    vector<string> nama = {"|N|", "|A|", "|B|", "|A irisan B|", "|A gabungan B|", "|A gabungan B komplemen|", "|Hanya A|", "|Hanya B|", "|A Xor B|"};
    vector<string> tanya = {"Masukan jumlah semesta - - - - - - - - : ", "Masukan jumlah anggota A - - - - - - - : ",
                            "Masukan jumlah anggota B - - - - - - - : ", "Jumlah yang masuk anggota A irisan B - : ",
                            "Jumlah yang masuk anggota A gabungan B : ", "Jumlah yang tidak masuk A maupun B - - : "};
    judulSoal("Perhitungan 2 Himpunan");
    for (int i = 0; i < 6; i++) v[i] = bacaNilai(tanya[i]);

    cout << "\n========== LANGKAH PENYELESAIAN ==========\n\n";
    Hitung2Himpunan(v);
    tampilkanHasil(nama, hasil2himpunan);
}

void TigaHimpunan(){
    vector<int> v(15, -1);   // 15 nilai: indeks 13 = tepat 2, indeks 14 = tepat 1
    vector<string> nama = {"|N|", "|A|", "|B|", "|C|", "|A irisan B|", "|A irisan C|", "|B irisan C|", "|A irisan B irisan C|",
                           "|A gabungan B gabungan C|", "|A gabungan B gabungan C komplemen|",
                           "|Hanya A|", "|Hanya B|", "|Hanya C|",
                           "Jumlah Tepat 2 Himpunan", "Jumlah Tepat 1 Himpunan"};
    vector<string> tanya = {"Masukan jumlah semesta - - - - - - - - - : ", "Masukan jumlah anggota A - - - - - - - - : ",
                            "Masukan jumlah anggota B - - - - - - - - : ", "Masukan jumlah anggota C - - - - - - - - : ",
                            "Jumlah anggota A irisan B- - - - - - - - : ", "Jumlah anggota A irisan C- - - - - - - - : ",
                            "Jumlah anggota B irisan C- - - - - - - - : ", "Jumlah anggota A irisan B irisan C - - - : ",
                            "Jumlah anggota A gabungan B gabungan C - : ", "Jumlah anggota tidak masuk A,B, maupun C : "};
    judulSoal("Perhitungan 3 Himpunan");
    for (int i = 0; i < 10; i++) v[i] = bacaNilai(tanya[i]);

    cout << "\n========== LANGKAH PENYELESAIAN ==========\n\n";
    Hitung3Himpunan(v);
    tampilkanHasil(nama, hasil3himpunan);
}

// Data soal rentang bilangan (diisi oleh RentangBilangan, dipakai oleh jumlahHabisBagi)
int awal = 1, akhir = 1;    // rentang bilangan: awal sampai akhir

// Banyak bilangan di rentang awal..akhir yang habis dibagi d
int jumlahHabisBagi(long long d){
    return akhir / d - (awal - 1) / d;
}

// Mencetak satu langkah penjelasan: judul, arti (boleh kosong), rumus, substitusi, dan hasil
void langkahRentang(const string& judul, const string& arti, const string& rumus, const string& substitusi, int hasil){
    cout << CYAN << ++langkah << ". " << judul << RESET << endl;
    if (arti != "") cout << "   Artinya   : " << arti << endl;
    cout << "   Rumus     : " << rumus << endl;
    cout << "   Substitusi: " << substitusi << " = " << hasil << endl << endl;
}

// Satu langkah: mencari banyak bilangan yang habis dibagi d, hasilnya dikembalikan
int langkahKelipatan(const string& nama, const string& arti, long long d){
    int hasil = jumlahHabisBagi(d);
    string D = to_string(d);
    langkahRentang("Mencari " + nama, arti + ", jadi d = " + D,
                   nama + " = akhir / d - (awal - 1) / d",
                   nama + " = " + to_string(akhir) + " / " + D + " - (" + to_string(awal) + " - 1) / " + D,
                   hasil);
    return hasil;
}

// Membaca angka sampai nilainya berada di antara kecil dan besar
int bacaRentang(const string& prompt, int kecil, int besar = numeric_limits<int>::max()){
    int x = bacaNilai(prompt);
    while (x < kecil || x > besar){
        cout << "Angka tidak valid!" << endl;
        x = bacaNilai(prompt);
    }
    return x;
}

void RentangBilangan(){
    system("cls");
    cout << "---------- Perhitungan Rentang Bilangan ----------\n";
    int banyak = bacaRentang("Banyak bilangan (pembagi + dilarang), 2 atau 3 : ", 2, 3);
    awal  = bacaRentang("Dari Bilangan   : ", 1);
    akhir = bacaRentang("Sampai Bilangan : ", awal);

    // ---------- pilih jenis soal ----------
    int pilihan, sub = 1;
    if (banyak == 2){
        cout << "\n1. Habis dibagi A atau B  /  A dan B\n"
             << "2. Tidak habis dibagi A atau B  /  A dan B\n"
             << "3. Habis dibagi A tetapi tidak habis dibagi B\n"
             << "4. Habis dibagi A atau B, tetapi tidak keduanya\n";
        pilihan = bacaRentang("Pilihan (1-4) : ", 1, 4);
    } else {
        cout << "\n1. Habis dibagi 3 bilangan  (atau / dan)\n"
             << "2. Tidak habis dibagi 3 bilangan  (atau / dan)\n"
             << "3. Habis dibagi 2 bilangan  (atau / dan), tetapi tidak habis dibagi 1 bilangan\n"
             << "4. Habis dibagi 1 bilangan tetapi tidak habis dibagi 2 bilangan lainnya\n";
        pilihan = bacaRentang("Pilihan (1-4) : ", 1, 4);
    }
    if (pilihan <= 2 || (banyak == 3 && pilihan == 3)) sub = bacaRentang("1. atau   2. dan  -> pilih (1-2) : ", 1, 2);

    // ---------- isi bilangan: pembagi dan dilarang disimpan terpisah ----------
    int jP;                                  // banyak bilangan pembagi (harus habis dibagi)
    if (pilihan == 1)      jP = banyak;      // semua bilangan harus habis dibagi
    else if (pilihan == 2) jP = 0;           // semua bilangan dilarang
    else if (pilihan == 3) jP = banyak - 1;  // semua pembagi, kecuali 1 yang dilarang
    else jP = (banyak == 2) ? 2 : 1;         // pilihan 4: 2 himpunan -> A dan B pembagi; 3 himpunan -> hanya A pembagi
    int jD = banyak - jP;                    // banyak bilangan dilarang (tidak boleh habis dibagi)
    vector<int> pembagi, dilarang;
    cout << "\n";
    for (int i = 0; i < jP; i++) pembagi.push_back(bacaRentang("Bilangan pembagi ke-" + to_string(i + 1) + "  : ", 1));
    for (int i = 0; i < jD; i++) dilarang.push_back(bacaRentang("Bilangan dilarang ke-" + to_string(i + 1) + " : ", 1));

    // untuk rumus, bilangan diurutkan menjadi A, B, C: pembagi dulu, lalu dilarang
    vector<int> p = pembagi;
    p.insert(p.end(), dilarang.begin(), dilarang.end());

    // ---------- penjelasan langkah penyelesaian ----------
    langkah = 0;
    cout << "\n========== LANGKAH PENYELESAIAN ==========\n\n";
    cout << "Pemisalan:\n";
    for (int i = 0; i < banyak; i++)
        cout << "  " << (char)('A' + i) << " = bilangan yang habis dibagi " << p[i] << (i < jP ? "   (pembagi)" : "   (dilarang)") << endl;
    cout << "\nBanyak bilangan yang habis dibagi d di rentang " << awal << " sampai " << akhir << " dihitung dengan:\n"
         << "  (banyak kelipatan d dari 1 sampai akhir) - (banyak kelipatan d sebelum awal)\n\n";

    // Langkah dasar: N, A, B
    int N = akhir - awal + 1;
    langkahRentang("Mencari |N|", "banyak seluruh bilangan dari " + to_string(awal) + " sampai " + to_string(akhir),
                   "|N| = akhir - awal + 1",
                   "|N| = " + to_string(akhir) + " - " + to_string(awal) + " + 1", N);
    string s0 = to_string(p[0]), s1 = to_string(p[1]);
    int A = langkahKelipatan("|A|", "habis dibagi " + s0, p[0]);
    int B = langkahKelipatan("|B|", "habis dibagi " + s1, p[1]);

    int jawab;
    if (banyak == 2){
        int AnB = langkahKelipatan("|A irisan B|", "habis dibagi " + s0 + " dan " + s1 + " sekaligus = habis dibagi KPK(" + s0 + ", " + s1 + ")", kpk(p[0], p[1]));
        int AuB = A + B - AnB;
        if (pilihan <= 2 && sub == 1) catat("|A gabungan B|", "|A| + |B| - |A irisan B|", {A, B, AnB}, AuB);   // butuh A gabungan B

        if (pilihan == 1){
            jawab = (sub == 1) ? AuB : AnB;                       // atau = AuB, dan = AnB (sudah dicari di atas)
        } else if (pilihan == 2){
            int yang = (sub == 1) ? AuB : AnB;
            jawab = N - yang;                                     // banyak bilangan - hasil pilihan 1
            catat("Jawaban", (sub == 1) ? "|N| - |A gabungan B|" : "|N| - |A irisan B|", {N, yang}, jawab);
        } else if (pilihan == 3){
            jawab = A - AnB;                                      // Hanya A
            catat("|Hanya A|", "|A| - |A irisan B|", {A, AnB}, jawab);
        } else {
            jawab = A + B - 2 * AnB;                              // A atau B tetapi tidak keduanya (Xor)
            catat("|A Xor B|", "|A| + |B| - 2 * |A irisan B|", {A, B, AnB}, jawab);
        }
    } else {
        string s2 = to_string(p[2]);
        int C = langkahKelipatan("|C|", "habis dibagi " + s2, p[2]);
        int AnB = langkahKelipatan("|A irisan B|", "habis dibagi " + s0 + " dan " + s1 + " sekaligus = habis dibagi KPK(" + s0 + ", " + s1 + ")", kpk(p[0], p[1]));
        int AnC = langkahKelipatan("|A irisan C|", "habis dibagi " + s0 + " dan " + s2 + " sekaligus = habis dibagi KPK(" + s0 + ", " + s2 + ")", kpk(p[0], p[2]));
        int BnC = langkahKelipatan("|B irisan C|", "habis dibagi " + s1 + " dan " + s2 + " sekaligus = habis dibagi KPK(" + s1 + ", " + s2 + ")", kpk(p[1], p[2]));
        int AnBnC = langkahKelipatan("|A irisan B irisan C|", "habis dibagi " + s0 + ", " + s1 + ", dan " + s2 + " sekaligus = habis dibagi KPK(" + s0 + ", " + s1 + ", " + s2 + ")", kpk3(p[0], p[1], p[2]));
        int AuBuC = A + B + C - AnB - AnC - BnC + AnBnC;
        if (pilihan <= 2 && sub == 1)
            catat("|A gabungan B gabungan C|", "|A| + |B| + |C| - |A irisan B| - |A irisan C| - |B irisan C| + |A irisan B irisan C|", {A, B, C, AnB, AnC, BnC, AnBnC}, AuBuC);

        if (pilihan == 1){
            jawab = (sub == 1) ? AuBuC : AnBnC;                   // atau = AuBuC, dan = AnBnC (sudah dicari di atas)
        } else if (pilihan == 2){
            int yang = (sub == 1) ? AuBuC : AnBnC;
            jawab = N - yang;                                     // banyak bilangan - hasil pilihan 1
            catat("Jawaban", (sub == 1) ? "|N| - |A gabungan B gabungan C|" : "|N| - |A irisan B irisan C|", {N, yang}, jawab);
        } else if (pilihan == 3){
            if (sub == 1){                                        // (A atau B) tetapi bukan C
                jawab = (A + B - AnB) - (AnC + BnC - AnBnC);
                catat("n((A gabungan B) - C)", "(|A| + |B| - |A irisan B|) - (|A irisan C| + |B irisan C| - |A irisan B irisan C|)", {A, B, AnB, AnC, BnC, AnBnC}, jawab);
            } else {                                              // (A dan B) tetapi bukan C
                jawab = AnB - AnBnC;
                catat("n((A irisan B) - C)", "|A irisan B| - |A irisan B irisan C|", {AnB, AnBnC}, jawab);
            }
        } else {
            jawab = A - AnB - AnC + AnBnC;                        // Hanya A
            catat("|Hanya A|", "|A| - |A irisan B| - |A irisan C| + |A irisan B irisan C|", {A, AnB, AnC, AnBnC}, jawab);
        }
    }

    cout << "============== JAWABAN ==============\n";
    cout << "Banyak bilangan yang memenuhi : " << jawab << endl;
    cout << "\nTekan Tombol Apapun Untuk Kembali Ke Main Menu..."; _getch();
}

int main(){
    while (true){
        system("cls");
        cout << "----------------------------------------------\n";
        cout << "   PROGRAM MENGHITUNG SOAL INKLUSI EKSKLUSI   \n";
        cout << "----------------------------------------------\n\n";
        cout << "Jenis Soal : \n1. 2 Himpunan\n2. 3 Himpunan\n3. Rentang Bilangan\n4. Keluar Program\n";

        int jenis;
        while (true){
            cout << "\nPilih Jenis Soal (1-4) : "; cin >> jenis;
            bool bukanAngka = cin.fail() || cin.peek() != '\n';
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (bukanAngka) cout << "Pilihan Tidak Valid! Harus berupa angka!\n";
            else if (jenis < 1 || jenis > 4) cout << "Pilihan Tidak Valid! Harus diantara 1-4!\n";
            else break;
        }

        if (jenis == 1) DuaHimpunan();
        else if (jenis == 2) TigaHimpunan();
        else if (jenis == 3) RentangBilangan();
        else if (jenis == 4){
            cout << "\nTerima Kasih Telah Menggunakan Proggram Ini :)\n";
            return 0;
        }
    }
}