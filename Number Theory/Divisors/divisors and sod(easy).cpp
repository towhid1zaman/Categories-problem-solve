
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

  ll n; cin >> n;
  ll res = 0;
  for(ll i = 1; i<=n/2; i++){
    if(n%i==0){
      cout<<i<<" ";
      res+=i;
    }
   }
   cout<<n<<endl;
   res+=n;
   cout<<"SUM "<<res<<endl;

}
