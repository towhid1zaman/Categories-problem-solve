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

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

vi adj[maxn];
int vis[maxn];
int dist[maxn];
int level[maxn];
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int child: adj[u]){
            if(vis[child]==0){
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[u]+1;
                level[dist[child]] ++;
            }
        }
    }
}
int main(){
        _ios;

        int node,edge; cin >> node >> edge;
        for(int i = 1; i<=edge;i++){
            int u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int Q; cin >> Q;
        while(Q--){
            int src,d;
            cin >> src >> d;

            for(int i = 0; i<=node;i++){
                vis[i] = 0;
                dist[i]=0;
                level[i]= 0;
            }
            bfs(src);
                cout<<level[d]<<endl;
          }




return 0;
}





