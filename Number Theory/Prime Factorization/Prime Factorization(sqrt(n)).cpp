#include "bits/stdc++.h"
using namespace std;
#define ll long long

vector<int>factorize(int n){
    vector<int>factor;
    for(int i = 2; i<=n/i;i++){
        if(n%i!=0)continue;
        factor.push_back(i);
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        factor.push_back(n);
    }

    return factor;
}
int main()
{
    int n;
    cin>>n;
    vector<int>pf = factorize(n);
    for(auto x: pf){
        cout<<x<<" ";
    }
    cout<<endl;

return 0;
}
