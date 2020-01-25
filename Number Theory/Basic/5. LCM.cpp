#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a, ll b){
    return a/ gcd(a,b)*b;
}

int main()
{

        ll a,b;
        while(cin>>a>>b){
            cout<<lcm(a,b)<<endl;
        }
return 0;
}



