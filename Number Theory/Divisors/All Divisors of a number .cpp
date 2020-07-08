#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<int> fact(int n){
    vector<int>v;
    for(int i = 1; i*i<=n;i++){
        if(n%i==0){
            v.push_back(i);
            if(i!=n/i){
                v.push_back(n/i);
            }
        }
    }
    return v;
}
int main(){
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif
        
        int n; cin >> n;
        vector<int>d=fact(n);
        sort(d.begin(),d.end());
        cout << d.size() << endl;
        for(auto i:d){
            cout << i << ' ';
        }
        cout<< endl;
        



return 0;
}

