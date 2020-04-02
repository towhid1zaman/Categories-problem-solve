#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<pair<int,int>>factorize(int n){
    vector<pair<int,int> > factor;
    for(int i = 2; i<=n/i; i++){
        if(n%i!=0)continue;
        int cnt=0;
        while(n%2==0){
            n/=i;
            cnt++;
        }
        factor.push_back({i,cnt});
    }
    if(n>1){
        factor.push_back({n,1});
    }
    return factor;
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int> >pf = factorize(n);

    for(auto x: pf){
        cout<<x.first<<"-"<<x.second<<endl;
    }

return 0;
}

