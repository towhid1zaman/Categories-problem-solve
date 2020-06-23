#include "bits/stdc++.h"
using namespace std;
#define ll long long
int p[10000005];
void sieve(){
    for(ll i=2;i<=10000000;i++){
        if(p[i]==0)
        for(ll j=i*i;j<=10000000;j+=i){
            if(p[j]==0)
            p[j]=i;
        }
    }
}
int main(){
            sieve();

            for(int i = 2; i<=100; i++){
                cout<<i<<' '<<p[i]<<endl;
            }cout<<endl;

return 0;
}


