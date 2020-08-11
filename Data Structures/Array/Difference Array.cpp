/*
	Problem: You are Given an array of N size, and Given Query Q,
	in each Query you are given l,r,x
	you have to do in given array add x to elements of indexed l to r.

*/


// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
std::vector<ll> arr,diff;

void Build(int n){
	diff[0] = arr[0];
	for(int i = 1; i<n;i++){
		diff[i] = arr[i] - arr[i-1];
	}
}

void Query(int l, int r, ll new_val){
	l--,r--;//if given query 1 indexed, because our array 0 indexed
	diff[l]+=new_val;
	diff[r+1]-=new_val;
}

void task(){
 	int n; cin >>n;
 	arr.resize(n);
 	diff.resize(n+1,0);
 	for(int i = 0; i<n; i++){
 		cin >> arr[i];
 	}
 	Build(n);
 	int Q; cin >> Q;
 	while(Q--){
 		int l,r;
 		ll new_val; 
 		cin >> l >> r >> new_val;
 		Query(l,r,new_val);
 	}

 	//final array
 	for(int i = 0; i<n; i++){
 		if(i==0)arr[i] = diff[i];
 		else arr[i] = diff[i] + arr[i-1]; //diff[i] = arr[i] - arr[i-1];

 		cout << arr[i] <<' ';
 	}
 	cout << endl;
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
5
3 4 5 6 1
2
1 5 2
3 4 3

5 6 10 11 3 
*/
