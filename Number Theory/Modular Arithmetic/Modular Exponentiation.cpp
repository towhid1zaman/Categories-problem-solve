#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define mod 100000007
ll bxpo(ll x,ll n){
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = (res*x)%mod;
        }
        x = (x*x)%mod;
        n = n/2;
    }
    return res;
}
//mod_inverse
ll mod_inverse(ll a) 
{
	return bxpo(a , mod-2);
}

int main()
{
    ll n,x;
    while(cin>>x>>n){
        cout<<"Exponentiation using BExp "<<bxpo(x,n)<<endl;
    }

return 0;
}
