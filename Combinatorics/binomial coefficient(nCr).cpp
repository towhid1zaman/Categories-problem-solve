/*
nCr = (n!/(k!*(n-k)!)
*/

// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


ll ncr(ll n, ll r){
    ll res = 1;
    ll range = min(r, n-r);
    for(ll i = 1; i<=range; i++){
        res *= (ceil(n-i+1)/i);
    }
    return res;
}

int main(){
        ll n,m;
        while(cin >> n >> m){
            if(n==0 and m==0)break;
            ll res = ncr(n,m);
            cout<<res<<endl;
        }



return 0;
}


