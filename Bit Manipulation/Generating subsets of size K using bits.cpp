
// </> : towhid1zaman

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;


/*
 *Generating subsets of size K using bits
 */

void task(){
	int n, k; cin >> n >> k;
	std::vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	for(int mask = 0; mask < (1<<n); mask++){
		if(__builtin_popcount(mask) != k)continue;
		std::vector<int> subset;
		for(int i = 0; i < n; i++){
			if(mask & (1 <<i ))subset.push_back(v[i]);
		}
		for(auto x: subset)cout << x << ' '; cout << endl;
	}
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


