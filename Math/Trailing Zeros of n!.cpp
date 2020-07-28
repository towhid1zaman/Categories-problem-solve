
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;

//Trailing Zeros of n!

ll n,m,b;
ll ans;
ll res(ll n){
    ll ans = 0;
    while(n){
        n/=5;
        ans+=n;
    }
    return ans;
}
void task(){
    cin >> n;
    ans = res(n);
    cout << ans << endl;
}

int main(){
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; //cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


