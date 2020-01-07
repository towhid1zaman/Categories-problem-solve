
 //   CF: Tman

#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll bxpo(ll x,ll n){
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = res*x;
        }
        x = x*x;
        n = n/2;
    }
    return res;
}

int main()
{
    ll n,x;
    while(cin>>x>>n){
        cout<<"Exponentiation using BExp "<<bxpo(x,n)<<endl;
    }

return 0;
}


