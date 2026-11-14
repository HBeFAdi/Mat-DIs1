#include <iostream>

#define ll long long

using namespace std;

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

int main (){
    int a, b;
    cin >> a;
    cin >> b;

    cout << endl;
    cout << kpk(a,b) << endl;
}