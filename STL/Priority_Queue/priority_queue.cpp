
// </> : towhid1zaman

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;


void task(){
    
    //priority_queue<int, std::vector<int> , greater<int> > Q; // small value first
     
    priority_queue<int> Q; // greater value first
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int x; cin >> x;
        Q.push(x);
    } 

    while(!Q.empty()){
        cout << Q.top() <<' ';
        Q.pop();
    }
    cout << endl;

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

/*
1
5
1 2 3 4 5 

5 4 3 2 1 

*/
