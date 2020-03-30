
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
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const int INF = 1e9 + 10;
const double pi = acos(-1.0);
const int mod = 998244353; // (int)1e9+7
const int maxn = 2000100;

vi adj[maxn];
int col[maxn];
int vis[maxn];
int C[2]; //C[0] means number of nodes color with 0
            //C[1] means number of nodes color with 1


ll bxpo(ll x,ll n){
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = (res*x)%mod;
        }
        n = n/2;
        x = (x*x)%mod;
    }
    return res;
}

int  dfs(int v, int c){
    vis[v] = 1;
    C[c]++;
    col[v] = c;

    for(auto child: adj[v]){
        if(vis[child]==0){
            int chek = dfs(child, c^1);// passing opposite color using xor
            if(chek==-1)
                return -1;
        }
        else{
            if(col[child]==col[v]){
                return -1;
            }
        }
    }
    return 0;
}
int main(){
        _ios;

        ll n,m;
        int T; cin >> T;
        while(T--){
            cin >> n >> m;

            for(int i = 1;i<=n; i++){
                adj[i].clear();
                vis[i] = 0;
            }
            for(int i = 1; i<=m; i++){
                int u,v; cin >> u >> v;
                adj[u].pb(v);
                adj[v].pb(u);
            }
            ll res = 1;
            bool flag = true;
            for(int i = 1; i<=n; i++){
                if(vis[i]==0){
                    C[0]=C[1]=0;
                    int  chek = dfs(i,0);
                    if(chek==-1){
                        flag = false;
                        break;
                    }
                    res = (res * (bxpo(2 , C[0]) + bxpo(2 , C[1]))) % mod;
                }

            }
            if(!flag){
                cout<<0<<endl;
            }
            else cout<<res<<endl;
        }



return 0;
}






