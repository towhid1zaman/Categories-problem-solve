
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back
#define inf (1<<29)

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

ll phi[maxn];

void phiGen(int n){
    for(int i = 1; i<=n; i++){
        phi[i] = i;
    }
    for(int p = 2; p<=n; p++){
        if(phi[p]==p){
            phi[p] = p-1;
            for(int i=2*p; i<=n; i+=p){
                phi[i] = (phi[i]/p)*(p-1);
            }
        }
    }
}

int main(){
        _ios;

        phiGen(maxn);
        int T; cin >> T;
        while(T--){
            int n; cin >> n;
            cout<<phi[n]<<endl;
        }

return 0;
}





