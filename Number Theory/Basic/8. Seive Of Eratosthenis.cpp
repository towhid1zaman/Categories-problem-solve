#include "bits/stdc++.h"
using namespace std;
#define ll long long

vector<int>prime;
void seive(int n){
    bool pmark[n+1];
    memset(pmark,true, sizeof pmark);
    for(int i = 2; i*i<=n;i++){
        /// true means prime
        if(pmark[i]==true){
            for(int p = i*i; p<=n;p+=i){
                pmark[p] = false;
            }
        }
    }
    for(int i = 2; i<=n;i++){
        if(pmark[i]){
            prime.push_back(i);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    seive(n);
    for(auto x: prime){
        cout<<x<<" ";
    }
    cout<<endl;

return 0;
}



