

// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

/*finding square root using binary search
 *given n, find sqrt(n)
 */

void task(){
        ll n; cin >> n;

        ll low = 0, hi = n;
        ll ans = -1; // -1, if nor found
        while(low <= hi){
            ll mid  = (low+hi)/2;
            if((mid*mid) == n){
                ans = mid;
                break;
            }
            else if((mid * mid) > n){
                hi = mid-1;
            }
            else low = mid+1;
        }

        cout << ans << endl;
}

int main(){
        
#ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        int T = 1; cin >> T;
        for(int __ = 1; __ <= T; __++){
            //cout <<"Case "<<__<<": ";
            task();
        }


/*array size ?
 *n==1 ?
 *different approach ?
*/        
return 0;
}
