#include <iostream>
#include <vector>
#include <string> // Ditambahkan untuk manipulasi string JSON

using namespace std;

vector<int> hasil2himpunan;

bool ada(int a, int b=0, int c=0, int d=0, int e=0, int f=0, int g=0, int h=0){
    return (a != -1 && b != -1 && c != -1 && d != -1 && e != -1 && f != -1 && g != -1 && h != -1);
}

void HitungDuaHimpunan(vector<int> &v){
    vector<int> old(9,0);
    int &S = v[0], &A = v[1], &B = v[2], &AnB = v[3], &AuB = v[4], &AuBc = v[5], &hA = v[6], &hB = v[7], &Xor = v[8];

    while (v != old){
        old = v;
        if (!ada(S) && ada(AuB, AuBc)) S = AuB + AuBc;      
        if (!ada(A) && ada(AuB, AnB, B)) A = AuB + AnB - B; 
        if (!ada(B) && ada(AuB, AnB, A)) B = AuB + AnB - A; 
        if (!ada(AnB) && ada(A, B, AuB)) AnB = A + B - AuB; 
        if (!ada(AuB)){                                     
            if (ada(A, B, AnB)) AuB = A + B - AnB;
            else if (ada(S, AuBc)) AuB = S - AuBc;
        }
        if (!ada(AuBc) && ada(S, AuB)) AuBc = S - AuB;      
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

int main(){
    vector<int> v(9,-1);

    for (int i = 0; i < 6; i++){
        cin >> v[i];
    }

    // Berikan Breakpoint di baris bawah ini setelah fungsi hitung selesai dipanggil
    HitungDuaHimpunan(v); 
    
    for (int i = 0; i < 9; i++){
        cout << v[i] << " - ";
    }
}
