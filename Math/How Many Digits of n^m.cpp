
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 200005;

//How Many Digits of n^m

ll n,m,b;
ll ans = inf;
void task(){
    cin >> n >> m;

    ans = floor(m*log10(n))+1;
    cout << ans << endl;
}

int main(){
        _
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


