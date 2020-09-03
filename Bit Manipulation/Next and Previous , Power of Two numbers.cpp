
// </> : towhid1zaman

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
// check power of two or not
 bool PowerOfTwo(int n){
 	return (n && !(n&(n-1)));
 }
/*print the exactly next and previous number that is power of 2
 * let n = 6, next p2 = 8, and pre p2 = 4
 */
ll previousPowerTwo(ll n){
    while(n&n-1){
        n&=n-1;
    }
    return n;
}
ll nextPowerTwo(ll n){
	ll next = 1;
	while(next<=n){
		next<<=1;
	}
	return next;
}
void task(){
       ll n;
       cin >> n;
       cout << previousPowerTwo(n-1) << endl;
       cout << nextPowerTwo(n+1) << endl;
}

int main(){
   
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
        
return 0;
}


