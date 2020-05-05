
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 20000;

vector<int>adj[maxn];
vector<int>res;
int vis[maxn];

void dfs(int node){
    vis[node] = 1;
    for(auto child:adj[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }

    res.push_back(node);
}

int main(){
        _ios;
        int n,m;
        cin >> n >> m;
        for(int i = 0; i<=n; i++){
            adj[i].clear();
            vis[i]=0;
        }
        res.clear();
        for(int i = 0; i<m; i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
        }

        for(int i= 1; i<=n; i++){
            if(vis[i]==0){
                dfs(i);
            }
        }
        reverse(all(res));
        for(auto x: res){
            cout<<x<<' ';
        }
        cout<<endl;

return 0;
}

