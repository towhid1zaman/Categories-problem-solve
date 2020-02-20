
///Bishu and his Girlfriend (Hackerearth)

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
#define ff first
#define ss second
#define pb push_back
#define sz(x) (int)x.size()

const ll INF = (ll)1e19;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;
vector<int>adj[maxn];
int vis[maxn];
int dist[maxn];

void dfs(int node, int d){
    vis[node] = 1;
    dist[node] = d;
    for(auto child: adj[node]){
        if(vis[child]==0){
            dfs(child,dist[node]+1);
        }
    }
}
int main(){
        _ios;
        fill(vis);
        int n;
        cin>>n;
        int e = n-1;
        for(int i = 1; i<=e;i++){
            int u,v;cin>>u>>v;
            adj[u].pb(v),adj[v].pb(u);
        }
        dfs(1,0);
        int q;
        cin>>q;
        int ans = -1,min_dist = 100000000;
        while(q--){
            int u;cin >> u;
            if(dist[u]<min_dist){
                min_dist = dist[u];
                ans = u;
            }
            else
                if(dist[u]==min_dist and u<ans){
                ans = u;
            }
        }
        cout<<ans<<endl;




return 0;
}

/*
6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4
*/





