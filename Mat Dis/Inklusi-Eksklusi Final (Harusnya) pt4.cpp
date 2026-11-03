#include <bits/stdc++.h>
#include <conio.h>

#define pb push_back
#define maxint numeric_limits<int>::max()
#define ll long long
#define RESET "\033[0m"
#define RED   "\033[31m"

using namespace std;

int awal, akhir;
vector<int> hasil2himpunan (9);
vector<int> hasil3himpunan (15);

ll fpb(ll a, ll b){
    while(b != 0){
        ll sisa = a % b;
        a = b;
        b = sisa;
    }
    return a;
}

ll kpk(ll a, ll b){
    ll hasil = a / fpb(a,b) * b;
    return (hasil > 2147483648LL ? 2147483648LL : hasil);
}

int JumlahHabisBagi(int p){
    return (akhir / p) - ((awal - 1) / p);
}

bool ada(int a, int b=0, int c=0, int d=0, int e=0, int f=0, int g=0, int h=0){
    return (a != -1 && b != -1 && c != -1 && d != -1 && e != -1 && f != -1 && g != -1 && h != -1);
}

int InputValid(string kalimat, string error, int a, int b){
    int x;
    while (true){
        cout << kalimat; cin >> x;
        bool salah = cin.fail() || cin.peek() != '\n' || x < a || x > b;
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (!salah) return x;
        cout << error << endl;
    }
}

void Permisalan(int n){
    vector<string> misal(n);
    cout << "Misalkan : \n";
    for (int i = 0; i < n; i++){
        cout << "  " << (char)('A'+i) << " = "; getline(cin, misal[i]);
    } 
}

void JawabanHimpunan(vector<string> nama, vector<int> v, int banyak){
    int ke = 0, cari = -1;
    vector<string> blmDiket;
    vector<int> jawab;
    cout << "\nYang belum diketahui : \n";
    for (int i = 0; i < (int)nama.size(); i++){
        if (v[i] == -1){
            ke++;
            banyak == 2 ? jawab.pb(hasil2himpunan[i]) : jawab.pb(hasil3himpunan[i]);
            blmDiket.pb(nama[i]);
            cout << ke << ". "<< blmDiket.back() << endl;
        }
    }

    while (true){
        cari = InputValid("\nYang ingin dicari (0 untuk kembali) : ", "Input tidak valid karena diluar Pilihan!", 0, (int)blmDiket.size());
        cout << "Jawaban : ";
        if (cari == 0) break;
        if (jawab[cari-1] == -1) cout << "Belum dapat ditentukan dengan data yang diberikan!\n";
        else cout << blmDiket[cari-1] << " = " << jawab[cari-1] << endl;
    }
}

void Hitung2Himpunan(vector<int> v){
    vector<int> old(9,0);
    int &N = v[0], &A = v[1], &B = v[2], &AnB = v[3], &AuB = v[4], &AuBc = v[5], &hA = v[6], &hB = v[7], &Xor = v[8];

    while (v != old){
        old = v;
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
    hasil2himpunan = v;
}

void Hitung3Himpunan(vector<int> v){
    vector<int> old (15,0);
    int &N = v[0], &A = v[1], &B = v[2], &C = v[3], &AnB = v[4], &AnC = v[5], &BnC = v[6], &AnBnC = v[7];
    int &AuBuC = v[8], &AuBuCc = v[9], &hA = v[10], &hB = v[11], &hC = v[12], &tpt2 = v[13], &tpt1 = v[14];

    while (v != old){
        old = v;
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
    hasil3himpunan = v;
}

void DuaHimpunan(){
    vector<int> v (9,-1);
    vector<string> nama = {"|N|", "|A|", "|B|", "|A irisan B|", "|A gabungan B|", "|A gabungan B komplemen|", "|Hanya A|", "|Hanya B|", "|A Xor B|"};
    vector<string> tanya = {"Masukan jumlah semesta - - - - - - - - : ", "Masukan jumlah anggota A - - - - - - - : ",
                            "Masukan jumlah anggota B - - - - - - - : ", "Jumlah yang masuk anggota A irisan B - : ",
                            "Jumlah yang masuk anggota A gabungan B : ", "Jumlah yang tidak masuk A maupun B - - : "};
    Permisalan(2);
    cout << "\nIsi angka yang diketahui, " << RED << "Tulis -1 Untuk Data yang TIDAK DIKETAHUI!!!\n" << RESET;
    for (int i = 0 ; i < 6; i++) v[i] = InputValid(tanya[i], "Input tidak valid. Masukkan bilangan bulat >= 0, atau -1 jika tidak diketahui.", -1, maxint);
    Hitung2Himpunan(v);
    JawabanHimpunan(nama, v, 2);
}

void TigaHimpunan(){
    vector<int> v (15,-1);
    vector<string> nama = {"|N|", "|A|", "|B|", "|C|", "|A irisan B|", "|A irisan C|", "|B irisan C|", "|A irisan B irisan C|",
                           "|A gabungan B gabungan C|", "|A gabungan B gabungan C komplemen|",
                           "|Hanya A|", "|Hanya B|", "|Hanya C|",
                           "Jumlah Tepat 2 Himpunan", "Jumlah Tepat 1 Himpunan"};
    vector<string> tanya = {"Masukan jumlah semesta - - - - - - - - - : ", "Masukan jumlah anggota A - - - - - - - - : ",
                            "Masukan jumlah anggota B - - - - - - - - : ", "Masukan jumlah anggota C - - - - - - - - : ",
                            "Jumlah anggota A irisan B- - - - - - - - : ", "Jumlah anggota A irisan C- - - - - - - - : ",
                            "Jumlah anggota B irisan C- - - - - - - - : ", "Jumlah anggota A irisan B irisan C - - - : ",
                            "Jumlah anggota A gabungan B gabungan C - : ", "Jumlah anggota tidak masuk A,B, maupun C : "};
    Permisalan(3);
    cout << "\nIsi angka yang diketahui, " << RED << "Tulis -1 Untuk Data yang TIDAK DIKETAHUI!!!\n" << RESET;
    for (int i = 0; i < 10; i++) v[i] = InputValid(tanya[i], "Input tidak valid. Masukkan bilangan bulat >= 0, atau -1 jika tidak diketahui.", -1, maxint);
    Hitung3Himpunan(v);
    JawabanHimpunan(nama, v, 3);
}

void HabiDibagi(int banyak){
    const vector<int>& h2 = hasil2himpunan;
    const vector<int>& h3 = hasil3himpunan;
    vector<int> p;
    vector<int> v;
    int opsi, subopsi, jawab;

    awal = InputValid("\nMasukan angka batas bawah : ","Input tidak valid. Harus lebih dari nol!", 0, maxint);
    akhir = InputValid("Masukan angka batas atas : ","Input tidak valid. Harus lebih dari batas bawah!", awal, maxint);

    if (banyak == 2){
        cout << "\nManakah Opsi dibawah ini yang ditanyakan di soal?\n" <<
                "1. Habis dibagi A (dan/atau) B\n" <<
                "2. Tidak habis dibagi A (dan/atau) B\n" <<
                "3. Habis dibagi A tetapi tidak habis dibagi B\n"
                "4. Habis dibagi A atau B, tetapi tidak keduanya\n";
    } else {
        cout << "\nManakan Opsi dibawah ini yang ditanyakan di soal?\n" <<
                "1. Habis dibagi ke 3 bilangan (dan/atau)\n" <<
                "2. Tidak habis dibagi ke 3 bilangan (dan/atau)\n" <<
                "3. Habis dibagi A (dan/atau) B, tetapi tidak habis dibagi C\n" <<
                "4. Habis dibagi A, tetapi tidak habis dibagi B (dan/atau) C\n";
    }
    opsi = InputValid("\nOpsi : ", "Input tidak valid karena diluar pilihan!", 1, 4);
    if (banyak == 3 || opsi <= 2) subopsi = InputValid("Pilih 1(Dan) / 2(Atau) : ","Input tidak valid karena diluar pilihan!", 1, 2);

    cout << endl;
    for (int i = 0; i < banyak; i++) p.pb(InputValid("Angka Pembagi ke-" + to_string(i+1) + " : ","Input tidak valid. Masukkan bilangan bulat >= 1", 1, maxint));

    for (int i = 0; i < 3; i++) i == 0 ? v.pb(akhir - awal + 1) : v.pb(JumlahHabisBagi(p[i-1]));
    if (banyak == 2){
        const int &N = h2[0], &AnB = h2[3], &AuB = h2[4], &AuBc = h2[5], &hA = h2[6], &Xor = h2[8];

        for (int i = 0; i < 6; i++) i == 0 ? v.pb(JumlahHabisBagi(kpk(p[0],p[1]))) : v.pb(-1);

        Hitung2Himpunan(v);
        switch(opsi){
            case 1 : subopsi == 1 ? jawab = AnB : jawab = AuB; break;
            case 2 : subopsi == 1 ? jawab = N - AnB : jawab = AuBc; break;
            case 3 : jawab = hA; break;
            case 4 : jawab = Xor; break;
        } 
    } else {
        const int &N = h3[0], &A = h3[1], &B = h3[2], &AnB = h3[4], &AnC = h3[5], &BnC = h3[6], &AnBnC = h3[7];
        const int &AuBuC = h3[8], &AuBuCc = h3[9], &hA = h3[10];
        for (int i = 0; i < 12; i++){
            switch(i){
                case 0 : v.pb(JumlahHabisBagi(p[2])); break;
                case 1 : v.pb(JumlahHabisBagi(kpk(p[0],p[1]))); break;
                case 2 : v.pb(JumlahHabisBagi(kpk(p[0],p[2]))); break;
                case 3 : v.pb(JumlahHabisBagi(kpk(p[1],p[2]))); break;
                case 4 : v.pb(JumlahHabisBagi(kpk(kpk(p[0],p[1]),p[2]))); break;
                default : v.pb(-1);
            }
        }
        Hitung3Himpunan(v);
        switch(opsi){
            case 1 : subopsi == 1 ? jawab = AnBnC : jawab = AuBuC; break;
            case 2 : subopsi == 1 ? jawab = N - AnBnC : jawab = AuBuCc; break;
            case 3 : subopsi == 1 ? jawab = AnB - AnBnC : jawab = (A + B - AnB) - (AnC + BnC - AnBnC); break;
            case 4 : subopsi == 1 ? jawab = A - AnBnC : jawab = hA; break;
        }
    }

    cout << "\nBanyak bilangan yang memenuhi semua syarat = " << jawab;
    cout << "\nPress Any Key to Continue..."; _getch();
}

int main(){
    while (true){
        system("cls");
        cout << "----------------------------------------------\n";
        cout << "   PROGRAM MENGHITUNG SOAL INKLUSI EKSKLUSI   \n";
        cout << "----------------------------------------------\n\n";

        string soal;
        cout << "Masukan Soal (ketik 0 untuk keluar dari program) : \n";
        getline(cin, soal);
        if (soal == "0") break;

        int soalrentang = InputValid("\nApakah soal termasuk soal habis dibagi? 1(Ya)/2(Tidak) : ", "Input tidak valid karena diluar pilihan!", 1, 2);
        int banyak = InputValid("Berapa jumlah himpunan di soal? (2/3) : ", "Input tidak valid karena diluar pilihan!", 2, 3);
        if (soalrentang == 1) HabiDibagi(banyak);
        else if (banyak == 2) DuaHimpunan();
        else TigaHimpunan();
    }
    cout << "----------------------------------------------\n" <<
            "  TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI  \n" <<
            "----------------------------------------------\n" << 
            " CREATOR : \n" <<
            " 1. Pradipa Rasyad              (NIM : 123260108)\n" <<
            " 2. Anargya Fahmi 'Ilmi Nugraha (NIM : 123260133)\n" <<
            " 3. Afnan Ario Wicaksonoo       (NIM : 123260135)\n" <<
            " 4. Arjuna Baharudin Zahir      (NIM : 123260098)\n";
}