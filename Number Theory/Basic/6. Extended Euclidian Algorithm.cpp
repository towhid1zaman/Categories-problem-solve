#include "bits/stdc++.h"
using namespace std;
#define ll long long
ll d,x,y;
void EEA(ll a, ll b){
   if(b==0){
    d = a;
    x = 1;
    y = 0;
   }
   else{
    EEA(b,a%b);
    ll temp = x;
    x = y;
    y = temp - (a/b)*y;
   }
}

int main()
{
    ll a,b;
    while(cin>>a>>b){
        cout<<EEA(a,b)<<endl;
    }


return 0;
}



