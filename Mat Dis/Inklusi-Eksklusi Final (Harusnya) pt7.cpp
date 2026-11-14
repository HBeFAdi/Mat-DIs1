#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <string>
#include <utility>

#define st first
#define nd second
#define ts to_string
#define pb push_back
#define ll long long
#define maxint numeric_limits<int>::max()
#define RESET "\033[0m"
#define RED   "\033[31m"
#define CYAN  "\033[36m"

using namespace std;

int awal, akhir;
vector<int> hasil2himpunan (9);
vector<int> hasil3himpunan (15);
vector<vector<string>> cara; // Vector 2D

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
    if (hasil > 2147483648LL) return 2147483648LL;
    else return hasil;
}

int JumlahHabisBagi(ll p){
    int hasil;
    hasil = (akhir / p) - ((awal - 1) / p);
    return hasil;
}

bool ada(int a, int b=0, int c=0, int d=0, int e=0, int f=0, int g=0, int h=0){
    bool kondisi = a != -1 && b != -1 && c != -1 && d != -1 && e != -1 && f != -1 && g != -1 && h != -1;
    return kondisi;
}

int InputValid(string kalimat, string error, int a, int b){
    bool salah = true;
    int x;
    while (salah) {
        cout << kalimat; cin >> x;
        if (cin.fail() || cin.peek() != '\n' || x < a || x > b){
            cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << error << RESET << endl;
        } else salah = false;
    }
    return x;
}

string rumus(vector<string> variabel, vector<int> nilai, string opr){
    string r;
    for (int i = 0; i < (int)variabel.size(); i++) r += variabel[i] + " " + opr[i] + " ";
    for (int i = 0; i < (int)nilai.size(); i++){
        r += ts(nilai[i]);
        if (i < (int)opr.size()) r += string(" ") + opr[i] + " ";
    }
    return r;
}

void Permisalan(int n){
    vector<string> misal(n);
    cout << "\nMisalkan : \n";
    for (int i = 0; i < n; i++){
        cout << "  " << (char)('A'+i) << " = "; getline(cin >> ws, misal[i]);
    }
}

void JawabanHimpunan(vector<string> nama, vector<int> v, int banyak){
    int langkah, cari, ke = 0;
    bool masihCari = true;
    const vector<int>& h2 = hasil2himpunan;
    const vector<int>& h3 = hasil3himpunan;
    vector<pair<string,int>> blmDiket;
    vector<pair<string,int>> diket;
    cout << "\nYang belum diketahui : \n";
    for (int i = 0; i < (int)v.size(); i++){
        if (v[i] == -1){
            ke++;
            blmDiket.pb({nama[i], banyak == 2 ? h2[i] : h3[i]});
            cout << ke << ". "<< blmDiket.back().st << endl;
        } else {
            diket.pb({nama[i], banyak == 2 ? h2[i] : h3[i]});
        }
    }
    while (masihCari) {
        cari = InputValid("\nYang ingin dicari (0 untuk kembali) : ", "Input tidak valid karena diluar Pilihan!", 0, (int)blmDiket.size());
        if (cari != 0){
            cout << "Jawaban : ";
            if (blmDiket[cari-1].nd == -1) cout << RED << blmDiket[cari-1].st << " Belum dapat ditentukan dengan data yang diberikan!\n" << RESET;
            else cout << CYAN << blmDiket[cari-1].st << " = " << blmDiket[cari-1].nd << RESET << endl;
        } else masihCari = false;
    }
    langkah = InputValid("\nApakah anda ingin melihat langkah langkahnya? 1(Ya) / 2(Tidak) : ","Input tidak valid karena diluar Pilihan!", 1, 2);
    if (langkah == 1){
        cout << "\nDiketahui : \n";
        for (int i = 0; i < (int)diket.size(); i++) cout << CYAN << " - " << diket[i].st << " = " << diket[i].nd << RESET << endl;
        cout << "\nDitanya : \n";
        for (int i = 0; i < (int)blmDiket.size(); i++) cout << CYAN << " - " << blmDiket[i].st << RESET << endl;
        cout << "\nJawab : \n";
        for (int i = 0; i < (int)cara.size(); i++) cout << CYAN << cara[i][0] << endl << cara[i][1] << RESET << endl << endl;
        if ((int)cara.size() != (int)blmDiket.size()) cout << RED << "Yang lainnya belum bisa ditentukan dengan data yang diberikan!\n" << RESET << endl;
    }
}

void Hitung2Himpunan(vector<int> v){
    vector<int> old(9,0);
    int &S = v[0], &A = v[1], &B = v[2], &AnB = v[3], &AuB = v[4], &AuBc = v[5], &hA = v[6], &hB = v[7], &Xor = v[8];
    cara.clear();

    while (v != old){
        old = v;
        if (!ada(S) && ada(AuB, AuBc)) {S = AuB + AuBc;
            cara.pb({"|S|", rumus({"AuB","(AuB)^c"}, {AuB,AuBc,S}, "+=")});}
        if (!ada(A) && ada(AuB, AnB, B)) {A = AuB + AnB - B;
            cara.pb({"|A|", rumus({"AuB","AnB","B"}, {AuB,AnB,B,A}, "+-=")});}
        if (!ada(B) && ada(AuB, AnB, A)) {B = AuB + AnB - A;
            cara.pb({"|B|", rumus({"AuB","AnB","A"}, {AuB,AnB,A,B}, "+-=")});}
        if (!ada(AnB) && ada(A, B, AuB)) {AnB = A + B - AuB;
            cara.pb({"|AnB|", rumus({"A","B","AuB"}, {A,B,AuB,AnB}, "+-=")});}
        if (!ada(AuB)){
            if (ada(A, B, AnB)) {AuB = A + B - AnB;
                cara.pb({"|AuB|", rumus({"A","B","AnB"}, {A,B,AnB,AuB}, "+-=")});}
            else if (ada(S, AuBc)) {AuB = S - AuBc;
                cara.pb({"|AuB|", rumus({"S","(AuB)^c"}, {S,AuBc,AuB}, "-=")});}
        }
        if (!ada(AuBc) && ada(S, AuB)) {AuBc = S - AuB;
            cara.pb({"|(AuB)^c|", rumus({"S","AuB"}, {S,AuB,AuBc}, "-=")});}
        if (!ada(hA)){
            if (ada(A, AnB)) {hA = A - AnB;
                cara.pb({"|Hanya A|", rumus({"A","AnB"}, {A,AnB,hA}, "-=")});}
            else if (ada(AuB, B)) {hA = AuB - B;
                cara.pb({"|Hanya A|", rumus({"AuB","B"}, {AuB,B,hA}, "-=")});}
        }
        if (!ada(hB)){
            if (ada(B, AnB)) {hB = B - AnB;
                cara.pb({"|Hanya B|", rumus({"B","AnB"}, {B,AnB,hB}, "-=")});}
            else if (ada(AuB, A)) {hB = AuB - A;
                cara.pb({"|Hanya B|", rumus({"AuB","A"}, {AuB,A,hB}, "-=")});}
        }
        if (!ada(Xor)){
            if (ada(hA, hB)) {Xor = hA + hB;
                cara.pb({"|A Xor B|", rumus({"Hanya A","Hanya B"}, {hA,hB,Xor}, "+=")});}
            else if (ada(AuB, AnB)) {Xor = AuB - AnB;
                cara.pb({"|A Xor B|", rumus({"AuB","AnB"}, {AuB,AnB,Xor}, "-=")});}
        }
    }
    hasil2himpunan = v;
}

void Hitung3Himpunan(vector<int> v){
    vector<int> old (15,0);
    int &S = v[0], &A = v[1], &B = v[2], &C = v[3], &AnB = v[4], &AnC = v[5], &BnC = v[6], &AnBnC = v[7];
    int &AuBuC = v[8], &AuBuCc = v[9], &hA = v[10], &hB = v[11], &hC = v[12], &tpt2 = v[13], &tpt1 = v[14];
    cara.clear();

    while (v != old){
        old = v;
        if (!ada(S) && ada(AuBuC, AuBuCc)) {S = AuBuC + AuBuCc;
            cara.pb({"|S|", rumus({"AuBuC","(AuBuC)^c"}, {AuBuC,AuBuCc,S}, "+=")});}
        if (!ada(A) && ada(AuBuC, B, C, AnB, AnC, BnC, AnBnC)) {A = AuBuC - B - C + AnB + AnC + BnC - AnBnC;
            cara.pb({"|A|", rumus({"AuBuC","B","C","AnB","AnC","BnC","AnBnC"}, {AuBuC,B,C,AnB,AnC,BnC,AnBnC,A}, "--+++-=")});}
        if (!ada(B) && ada(AuBuC, A, C, AnB, AnC, BnC, AnBnC)) {B = AuBuC - A - C + AnB + AnC + BnC - AnBnC;
            cara.pb({"|B|", rumus({"AuBuC","A","C","AnB","AnC","BnC","AnBnC"}, {AuBuC,A,C,AnB,AnC,BnC,AnBnC,B}, "--+++-=")});}
        if (!ada(C) && ada(AuBuC, A, B, AnB, AnC, BnC, AnBnC)) {C = AuBuC - A - B + AnB + AnC + BnC - AnBnC;
            cara.pb({"|C|", rumus({"AuBuC","A","B","AnB","AnC","BnC","AnBnC"}, {AuBuC,A,B,AnB,AnC,BnC,AnBnC,C}, "--+++-=")});}
        if (!ada(AnB) && ada(AuBuC, A, B, C, AnC, BnC, AnBnC)) {AnB = A + B + C - AnC - BnC + AnBnC - AuBuC;
            cara.pb({"|AnB|", rumus({"A","B","C","AnC","BnC","AnBnC","AuBuC"}, {A,B,C,AnC,BnC,AnBnC,AuBuC,AnB}, "++--+-=")});}
        if (!ada(AnC) && ada(AuBuC, A, B, C, AnB, BnC, AnBnC)) {AnC = A + B + C - AnB - BnC + AnBnC - AuBuC;
            cara.pb({"|AnC|", rumus({"A","B","C","AnB","BnC","AnBnC","AuBuC"}, {A,B,C,AnB,BnC,AnBnC,AuBuC,AnC}, "++--+-=")});}
        if (!ada(BnC) && ada(AuBuC, A, B, C, AnB, AnC, AnBnC)) {BnC = A + B + C - AnB - AnC + AnBnC - AuBuC;
            cara.pb({"|BnC|", rumus({"A","B","C","AnB","AnC","AnBnC","AuBuC"}, {A,B,C,AnB,AnC,AnBnC,AuBuC,BnC}, "++--+-=")});}
        if (!ada(AnBnC) && ada(AuBuC, A, B, C, AnB, AnC, BnC)) {AnBnC = AuBuC - A - B - C + AnB + AnC + BnC;
            cara.pb({"|AnBnC|", rumus({"AuBuC","A","B","C","AnB","AnC","BnC"}, {AuBuC,A,B,C,AnB,AnC,BnC,AnBnC}, "---+++=")});}
        if (!ada(AuBuC)){
            if (ada(A, B, C, AnB, AnC, BnC, AnBnC)) {AuBuC = A + B + C - AnB - AnC - BnC + AnBnC;
                cara.pb({"|AuBuC|", rumus({"A","B","C","AnB","AnC","BnC","AnBnC"}, {A,B,C,AnB,AnC,BnC,AnBnC,AuBuC}, "++---+=")});}
            else if (ada(S, AuBuCc)) {AuBuC = S - AuBuCc;
                cara.pb({"|AuBuC|", rumus({"S","(AuBuC)^c"}, {S,AuBuCc,AuBuC}, "-=")});}
        }
        if (!ada(AuBuCc) && ada(S, AuBuC)) {AuBuCc = S - AuBuC;
            cara.pb({"|(AuBuC)^c|", rumus({"S","AuBuC"}, {S,AuBuC,AuBuCc}, "-=")});}
        if (!ada(hA)){
            if (ada(A, AnB, AnC, AnBnC)) {hA = A - AnB - AnC + AnBnC;
                cara.pb({"|Hanya A|", rumus({"A","AnB","AnC","AnBnC"}, {A,AnB,AnC,AnBnC,hA}, "--+=")});}
            else if (ada(AuBuC, B, C, BnC)) {hA = AuBuC - B - C + BnC;
                cara.pb({"|Hanya A|", rumus({"AuBuC","B","C","BnC"}, {AuBuC,B,C,BnC,hA}, "--+=")});}
        }
        if (!ada(hB)){
            if (ada(B, AnB, BnC, AnBnC)) {hB = B - AnB - BnC + AnBnC;
                cara.pb({"|Hanya B|", rumus({"B","AnB","BnC","AnBnC"}, {B,AnB,BnC,AnBnC,hB}, "--+=")});}
            else if (ada(AuBuC, A, C, AnC)) {hB = AuBuC - A - C + AnC;
                cara.pb({"|Hanya B|", rumus({"AuBuC","A","C","AnC"}, {AuBuC,A,C,AnC,hB}, "--+=")});}
        }
        if (!ada(hC)){
            if (ada(C, AnC, BnC, AnBnC)) {hC = C - AnC - BnC + AnBnC;
                cara.pb({"|Hanya C|", rumus({"C","AnC","BnC","AnBnC"}, {C,AnC,BnC,AnBnC,hC}, "--+=")});}
            else if (ada(AuBuC, A, B, AnB)) {hC = AuBuC - A - B + AnB;
                cara.pb({"|Hanya C|", rumus({"AuBuC","A","B","AnB"}, {AuBuC,A,B,AnB,hC}, "--+=")});}
        }
        if (!ada(tpt2)){
            if (ada(AnB, AnC, BnC, AnBnC)) {tpt2 = AnB + AnC + BnC - 3 * AnBnC;
                cara.pb({"Jumlah Tepat 2 Himpunan", rumus({"AnB","AnC","BnC","3","(AnBnC)"}, {AnB,AnC,BnC,3,AnBnC,tpt2}, "++-*=")});}
            else if (ada(AuBuC, tpt1, AnBnC)) {tpt2 = AuBuC - tpt1 - AnBnC;
                cara.pb({"Jumlah Tepat 2 Himpunan", rumus({"AuBuC","Tepat 1","AnBnC"}, {AuBuC,tpt1,AnBnC,tpt2}, "--=")});}
        }
        if (!ada(tpt1)){
            if (ada(hA, hB, hC)) {tpt1 = hA + hB + hC;
                cara.pb({"Jumlah Tepat 1 Himpunan", rumus({"Hanya A","Hanya B","Hanya C"}, {hA,hB,hC,tpt1}, "++=")});}
            else if (ada(AuBuC, A, B, C, AnBnC)) {tpt1 = 2 * AuBuC - (A + B + C) + AnBnC;
                cara.pb({"Jumlah Tepat 1 Himpunan", rumus({"2","(AuBuC)","(A + B + C)","AnBnC"}, {2,AuBuC,A+B+C,AnBnC,tpt1}, "*-+=")});}
            else if (ada(AuBuC, AnB, AnC, BnC, AnBnC)) {tpt1 = AuBuC - AnB - AnC - BnC + 2 * AnBnC;
                cara.pb({"Jumlah Tepat 1 Himpunan", rumus({"AuBuC","AnB","AnC","BnC","2","(AnBnC)"}, {AuBuC,AnB,AnC,BnC,2,AnBnC,tpt1}, "---+*=")});}
        }
    }
    hasil3himpunan = v;
}

void DuaHimpunan(){
    vector<int> v (9,-1);
    vector<string> nama = {"|S|", "|A|", "|B|", "|A irisan B|", "|A gabungan B|", "|A gabungan B komplemen|", "|Hanya A|", "|Hanya B|", "|A Xor B|"};
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
    vector<string> nama = {"|S|", "|A|", "|B|", "|C|", "|A irisan B|", "|A irisan C|", "|B irisan C|", "|A irisan B irisan C|",
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

void HabisDibagi(int banyak){
    const vector<int>& h2 = hasil2himpunan;
    const vector<int>& h3 = hasil3himpunan;
    vector<int> p;
    vector<int> v;
    int opsi, subopsi, jawab;

    awal = InputValid("\nMasukan bilangan batas bawah : ","Input tidak valid. Harus lebih dari nol!", 1, maxint);
    akhir = InputValid("Masukan bilangan batas atas  : ","Input tidak valid. Harus lebih dari atau sama dengan batas bawah(awal)!", awal, maxint);

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
    for (int i = 0; i < banyak; i++) p.pb(InputValid("Bilangan Pembagi ke-" + ts(i+1) + " : ","Input tidak valid. Masukkan bilangan bulat >= 1", 1, maxint));

    // S, A, B kita masukan ke vector v terlebih dahulu karena baik 2 atau 3 himpunan memiliki ketiga variabel tersebut
    // di index yang sama yaitu (0, 1, 2).
    // A n B juga ada di kedua jenis himpunan, tetapi posisinya berbeda:
    // di 2 himpunan A n B ada di index 3, sedangkan di 3 himpunan ada di index 4 karena index 3 dipakai untuk C.
    // Karena posisinya yang berbeda, A n B tidak saya masukkan terlebih dahulu.
    for (int i = 0; i < 3; i++) i == 0 ? v.pb(akhir - awal + 1) : v.pb(JumlahHabisBagi(p[i-1]));

    if (banyak == 2){
        const int &S = h2[0], &AnB = h2[3], &AuB = h2[4], &AuBc = h2[5], &hA = h2[6], &Xor = h2[8];
        
        // Masukan A n B ke vector v dan karena Hitung2Himpunan butuh 9 data, sisanya kita beri nilai -1(tidak diketahui)
        for (int i = 0; i < 6; i++) i == 0 ? v.pb(JumlahHabisBagi(kpk(p[0],p[1]))) : v.pb(-1);

        Hitung2Himpunan(v);
        switch(opsi){
            case 1 : subopsi == 1 ? jawab = AnB : jawab = AuB; break;
            case 2 : subopsi == 1 ? jawab = S - AnB : jawab = AuBc; break;
            case 3 : jawab = hA; break;
            case 4 : jawab = Xor; break;
        }
    } else {
        const int &S = h3[0], &A = h3[1], &B = h3[2], &AnB = h3[4], &AnC = h3[5], &BnC = h3[6], &AnBnC = h3[7];
        const int &AuBuC = h3[8], &AuBuCc = h3[9], &hA = h3[10];
        for (int i = 0; i < 12; i++){
            switch(i){
                case 0 : v.pb(JumlahHabisBagi(p[2])); break;                     // Masukan C ke vector v
                case 1 : v.pb(JumlahHabisBagi(kpk(p[0],p[1]))); break;           // Masukan A n B ke vector v
                case 2 : v.pb(JumlahHabisBagi(kpk(p[0],p[2]))); break;           // Masukan A n C ke vector v
                case 3 : v.pb(JumlahHabisBagi(kpk(p[1],p[2]))); break;           // Masukan B n C ke vector v
                case 4 : v.pb(JumlahHabisBagi(kpk(kpk(p[0],p[1]),p[2]))); break; // Masukan A n B n C ke vector v
                default : v.pb(-1);                                              // Karena Hitung3Himpunan butuh 15 data, sisanya kita beri nilai -1(tidak diketahui)
            }
        }
        Hitung3Himpunan(v);
        switch(opsi){
            case 1 : subopsi == 1 ? jawab = AnBnC : jawab = AuBuC; break;
            case 2 : subopsi == 1 ? jawab = S - AnBnC : jawab = AuBuCc; break;
            case 3 : subopsi == 1 ? jawab = AnB - AnBnC : jawab = (A + B - AnB) - (AnC + BnC - AnBnC); break;
            case 4 : subopsi == 1 ? jawab = A - AnBnC : jawab = hA; break;
        }
    }
    cout << CYAN << "\nBanyak bilangan yang memenuhi semua syarat = " << jawab << RESET << endl;
}

int main(){
    int kembali;
    do {
        int soalHB, banyak;
        system("cls");
        cout << "--------------------------------------------------\n";
        cout << "     PROGRAM MENGHITUNG SOAL INKLUSI EKSKLUSI     \n";
        cout << "--------------------------------------------------\n\n";

        string soal;
        cout << "Masukan Soal : \n";
        getline(cin >> ws, soal);
        
        soalHB = InputValid("\nApakah soal termasuk soal habis dibagi? 1(Ya)/2(Tidak) : ", "Input tidak valid karena diluar pilihan!", 1, 2);
        if (soalHB == 1) {
            banyak = InputValid("Berapa jumlah angka pembagi di soal? (2/3) : ", "Input tidak valid karena diluar pilihan!", 2, 3);
            HabisDibagi(banyak);
        } else {
            banyak = InputValid("Berapa jumlah himpunan di soal? (2/3) : ", "Input tidak valid karena diluar pilihan!", 2, 3);
            if (banyak == 2) DuaHimpunan();
            else TigaHimpunan();
        }

        kembali = InputValid("Apakah ingin memasukan soal lagi? 1(Ya) / 2(Tidak): ", "Input tidak valid karena diluar pilihan!", 1, 2);
    } while (kembali == 1);
    cout << "\n--------------------------------------------------\n" <<
            "    TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI    \n" <<
            "--------------------------------------------------\n" << 
            " CREATOR : \n" <<
            " 1. Pradipa Rasyad              (NIM : 123260108)\n" <<
            " 2. Anargya Fahmi 'Ilmi Nugraha (NIM : 123260133)\n" <<
            " 3. Afnan Ario Wicaksonoo       (NIM : 123260135)\n" <<
            " 4. Arjuna Baharudin Zahir      (NIM : 123260098)\n";
}
// !^!*!$(!^! !*!!(@%!$
// (^-#
// !@#@^)!)*