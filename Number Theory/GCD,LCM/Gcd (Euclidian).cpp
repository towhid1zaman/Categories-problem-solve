#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
int main()
{
        ll a,b;
        while(cin>>a>>b){
            cout<<gcd(a,b)<<endl;
        }

return 0;
}
