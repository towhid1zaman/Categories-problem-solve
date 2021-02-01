/*
	Problem: You are Given an array of N size, and Given Query Q,
	in each Query you are given l,r;
	you have to do return sum of elements of indexed l to r.
*/


// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
std::vector<ll>arr,pref;

void Build(int n){
	for(int i = 1; i<=n; i++){
		pref[i] = pref[i-1]+arr[i];
	}
	/*
	Alternatively, we can write(Built in function)
	vector<int> prefix = a;
	partial_sum(prefix.begin(), prefix.end(), prefix.begin());
	The prefix sum would be stored in the vector prefix
	*/
}

ll Query(int left, int right){
	return pref[right] - pref[left-1];
}

void task(){
 	int n; cin >> n;
 	arr.resize(n+1);
 	pref.resize(n+1,0);
 	for(int i = 1; i<=n; i++){
 		cin >> arr[i];
 	}
 	Build(n);
 	int Q; cin >> Q;
 	while(Q--){
 		int left, right;
 		cin >> left >> right;
 		cout << Query(left, right) << endl;
 	}
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


/*
6
1 2 3 4 5 6 
3
1 2
3 4
1 6

3
7
21

*/
