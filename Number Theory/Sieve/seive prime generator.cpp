#include<bits/stdc++.h>
using namespace std;
using LL = long long;
vector<int>v;
void seive(int n){
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        for(int p= 2; p*p<=n;p++)
        {
            /// true that means prime
            if(prime[p]==true)
            {
                ///updates all multiplies of p greater than or equal to square of it
                    for(int i = p*p;i<=n;i+=p){
                        prime[i] = false;
                    }

            }
        }
        for(int i = 2; i<=n;i++){
            if(prime[i]==true){
                v.push_back(i);
            }
        }
}
int main()
{

            int n;
            cin>>n;
            seive(n);
            int sz = v.size();
                for(int i = 0; i<sz;i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;

            return 0;

}

