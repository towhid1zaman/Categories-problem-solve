//https://codeforces.com/contest/20/problem/B


/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int mod = 1000000007;

void task(){
    sp(9);
    ll a, b, c; cin >> a >> b >> c;
    long double cpa = a, cpb = b, cpc = c;
    if(a==0){
        if(b==0){
            if(c==0)cout << (int)-1 << endl;
            else cout << (int)0 << endl;
        }
        else{
            cout << (int)1 << endl;
            cout << -cpc/cpb << endl;
        }
    }
    else{
        long double D = (b*b) - (4*a*c);
        if(D < 0){
            cout << 0 << endl;
        }
        else if(D == 0){
            cout << (int)1 << endl;
            cout << -cpb/(2*cpa) << endl;
        }
        else{
            long double r1 = (-cpb + sqrt(D))/(2*cpa);            
            long double r2 = (-cpb - sqrt(D))/(2*cpa);            
            cout << (int)2 << endl;
            cout << min(r1, r2) << endl;
            cout << max(r1, r2) << endl;
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
