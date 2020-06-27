/*
given a and m, function finds x for a * x = 1 (mod m)
24 * x = 1 (mod 5)
24 = x*exp(-1) (mod 5)
x = 4
*/


// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 10000000;

int  modinv(int  a, int  n, int  m){
    int  res = 1;
    while(n){
        if(n%2==1) res = (res*a)%m;
        n/=2;
        a = (a*a)%m;
    }
    return res;
}

int main(){
        _
        int  a,m; cin >> a >> m;
        cout << modinv(a,m-2,m) << endl;
return 0;
}

