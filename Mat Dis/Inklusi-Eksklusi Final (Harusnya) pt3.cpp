#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <conio.h>

#define RESET "\033[0m"
#define RED   "\033[31m"

using namespace std;

// Data soal rentang bilangan (diisi oleh RentangBilangan, dipakai oleh jumlahHabisBagi)
int awal = 1, akhir = 1;    // rentang bilangan: awal sampai akhir

// Hasil akhir perhitungan disimpan di sini, lalu ditampilkan oleh DuaHimpunan / TigaHimpunan
vector<int> hasil2himpunan (9);
vector<int> hasil3himpunan (15);

// FPB dengan algoritma Euclid
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
    cout << "\n============== HASIL AKHIR ==============\n";
    for (size_t i = 0; i < nama.size(); i++){
        cout << left << setw(36) << nama[i] << ": ";
        if (v[i] == -1) cout << "Belum dapat ditentukan dengan data yang diberikan!" << endl;
        else cout << v[i] << endl;
    }
    cout << "\nTekan Tombol Apapun Untuk Kembali Ke Main Menu..."; _getch();
}

// ======================= PERHITUNGAN =======================
// v berisi data awal (6 angka pertama = hasil input, sisanya -1).
// Hasil akhir disimpan di hasil2himpunan.
void Hitung2Himpunan(vector<int> v){
    vector<int> l(9, 0);
    // Nama pendek untuk setiap isi vector v (referensi), supaya rumus mudah dibaca
    int &N = v[0], &A = v[1], &B = v[2], &AnB = v[3], &AuB = v[4], &AuBc = v[5], &hA = v[6], &hB = v[7], &Xor = v[8];
    // Ulangi sampai tidak ada nilai baru yang berhasil dihitung (v sama dengan l)
    while (v != l){
        l = v;
        if (!ada(N) && ada(AuB, AuBc)) N = AuB + AuBc;
        if (!ada(A) && ada(AuB, AnB, B)) A = AuB + AnB - B;
        if (!ada(B) && ada(AuB, AnB, A)) B = AuB + AnB - A;
        if (!ada(AnB) && ada(A, B, AuB)) AnB = A + B - AuB;
        if (!ada(AuB)){
            if (ada(A, B, AnB)) AuB = A + B - AnB;
            else if (ada(N, AuBc)) AuB = N - AuBc;
        }
        if (!ada(AuBc) && ada(N, AuB)) AuBc = N - AuB;
        if (!ada(hA)){
            if (ada(A, AnB)) hA = A - AnB;
            else if (ada(AuB, B)) hA = AuB - B;
        }
        if (!ada(hB)){
            if (ada(B, AnB)) hB = B - AnB;
            else if (ada(AuB, A)) hB = AuB - A;
        }
        if (!ada(Xor)){
            if (ada(hA, hB)) Xor = hA + hB;
            else if (ada(AuB, AnB)) Xor = AuB - AnB;
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
    while (v != l){
        l = v;
        if (!ada(N) && ada(AuBuC, AuBuCc)) N = AuBuC + AuBuCc;
        if (!ada(A) && ada(AuBuC, B, C, AnB, AnC, BnC, AnBnC)) A = AuBuC - B - C + AnB + AnC + BnC - AnBnC;
        if (!ada(B) && ada(AuBuC, A, C, AnB, AnC, BnC, AnBnC)) B = AuBuC - A - C + AnB + AnC + BnC - AnBnC;
        if (!ada(C) && ada(AuBuC, A, B, AnB, AnC, BnC, AnBnC)) C = AuBuC - A - B + AnB + AnC + BnC - AnBnC;
        if (!ada(AnB) && ada(AuBuC, A, B, C, AnC, BnC, AnBnC)) AnB = A + B + C - AnC - BnC + AnBnC - AuBuC;
        if (!ada(AnC) && ada(AuBuC, A, B, C, AnB, BnC, AnBnC)) AnC = A + B + C - AnB - BnC + AnBnC - AuBuC;
        if (!ada(BnC) && ada(AuBuC, A, B, C, AnB, AnC, AnBnC)) BnC = A + B + C - AnB - AnC + AnBnC - AuBuC;
        if (!ada(AnBnC) && ada(AuBuC, A, B, C, AnB, AnC, BnC)) AnBnC = AuBuC - A - B - C + AnB + AnC + BnC;
        if (!ada(AuBuC)){
            if (ada(A, B, C, AnB, AnC, BnC, AnBnC)) AuBuC = A + B + C - AnB - AnC - BnC + AnBnC;
            else if (ada(N, AuBuCc)) AuBuC = N - AuBuCc;
        }
        if (!ada(AuBuCc) && ada(N, AuBuC)) AuBuCc = N - AuBuC;
        if (!ada(hA)){
            if (ada(A, AnB, AnC, AnBnC)) hA = A - AnB - AnC + AnBnC;
            else if (ada(AuBuC, B, C, BnC)) hA = AuBuC - B - C + BnC;
        }
        if (!ada(hB)){
            if (ada(B, AnB, BnC, AnBnC)) hB = B - AnB - BnC + AnBnC;
            else if (ada(AuBuC, A, C, AnC)) hB = AuBuC - A - C + AnC;
        }
        if (!ada(hC)){
            if (ada(C, AnC, BnC, AnBnC)) hC = C - AnC - BnC + AnBnC;
            else if (ada(AuBuC, A, B, AnB)) hC = AuBuC - A - B + AnB;
        }
        if (!ada(tpt2)){
            if (ada(AnB, AnC, BnC, AnBnC)) tpt2 = AnB + AnC + BnC - 3 * AnBnC;
            else if (ada(AuBuC, tpt1, AnBnC)) tpt2 = AuBuC - tpt1 - AnBnC;
        }
        if (!ada(tpt1)){
            if (ada(hA, hB, hC)) tpt1 = hA + hB + hC;
            else if (ada(AuBuC, A, B, C, AnBnC)) tpt1 = 2 * AuBuC - (A + B + C) + AnBnC;
            else if (ada(AuBuC, AnB, AnC, BnC, AnBnC)) tpt1 = AuBuC - AnB - AnC - BnC + 2 * AnBnC;
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

    Hitung3Himpunan(v);
    tampilkanHasil(nama, hasil3himpunan);
}

// Banyak bilangan di rentang awal..akhir yang habis dibagi d
int jumlahHabisBagi(long long d){
    return akhir / d - (awal - 1) / d;
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

    // ---------- perhitungan ----------
    int N = akhir - awal + 1;
    int A = jumlahHabisBagi(p[0]);
    int B = jumlahHabisBagi(p[1]);
    int jawab;

    if (banyak == 2){
        int AnB = jumlahHabisBagi(kpk(p[0], p[1]));
        int AuB = A + B - AnB;

        if (pilihan == 1){
            jawab = (sub == 1) ? AuB : AnB;                       // atau = AuB, dan = AnB
        } else if (pilihan == 2){
            jawab = N - ((sub == 1) ? AuB : AnB);                 // banyak bilangan - hasil pilihan 1
        } else if (pilihan == 3){
            jawab = A - AnB;                                      // Hanya A
        } else {
            jawab = A + B - 2 * AnB;                              // A atau B tetapi tidak keduanya (Xor)
        }
    } else {
        int C = jumlahHabisBagi(p[2]);
        int AnB = jumlahHabisBagi(kpk(p[0], p[1]));
        int AnC = jumlahHabisBagi(kpk(p[0], p[2]));
        int BnC = jumlahHabisBagi(kpk(p[1], p[2]));
        int AnBnC = jumlahHabisBagi(kpk3(p[0], p[1], p[2]));
        int AuBuC = A + B + C - AnB - AnC - BnC + AnBnC;

        if (pilihan == 1){
            jawab = (sub == 1) ? AuBuC : AnBnC;                   // atau = AuBuC, dan = AnBnC
        } else if (pilihan == 2){
            jawab = N - ((sub == 1) ? AuBuC : AnBnC);             // banyak bilangan - hasil pilihan 1
        } else if (pilihan == 3){
            if (sub == 1) jawab = (A + B - AnB) - (AnC + BnC - AnBnC);   // (A atau B) tetapi bukan C
            else          jawab = AnB - AnBnC;                           // (A dan B) tetapi bukan C
        } else {
            jawab = A - AnB - AnC + AnBnC;                        // Hanya A
        }
    }

    cout << "\n============== JAWABAN ==============\n";
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

        switch(jenis) {
            case 1 : DuaHimpunan(); break;
            case 2 : TigaHimpunan(); break;
            case 3 : RentangBilangan(); break;
            case 4 : {
                cout << "\nTerima Kasih Telah Menggunakan Program Ini :)\n";
                return 0;
            }
        }
    }
}