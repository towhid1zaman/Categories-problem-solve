
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            ll n; cin >> n;
            ll ans = 1;
            for(int i = 2; i*i<=n; i++){
                    int cnt = 0;
                    while(n%i==0){
                        cnt++;
                        n/=i;
                    }
                    if(cnt!=0)ans*=(cnt+1);
            }
            if(n>1)ans*=2;
            cout<<ans<<endl;
        }


return 0;
}

