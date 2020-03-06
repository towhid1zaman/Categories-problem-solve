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
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000010;

int n,m;
vi adj[maxn];
vi color[maxn];

/// d array holds the distance from each node to the end point
/// ans array holds the weight of each edge on the shortest path
int vis[maxn], d[maxn], ans[maxn];

///start from node n
void bfs1(){
    queue<int>q;
    q.push(n);
    d[n] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==1)return;
        for(int i = 0; i<adj[u].size();i++){
            int v = adj[u][i];
            if(d[v]<0){
                ///All adjacent points at the current point must have a distance of +1 from the end point
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

}

/// start from node 1
void bfs2(){
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==n)return;
        int min_c = INF;
        for(int i = 0; i<color[u].size();i++){
            int v = adj[u][i];
            int c = color[u][i];
            if(d[v]==d[u]-1){
                min_c = min(c,min_c);
            }
        }
        ///step is the index of the array holding the shortest edge weight sequence
        int step = d[1] - d[u];
        ///If no value is set, it is naturally set to the minimum weight found
        if(ans[step]==0) ans[step] = min_c;
        /// If the newly found minimum value in this round is smaller than that found in the previous round, update
        /// because each round only searches the neighborhood of a point, the minimum edge weight may take several rounds to find
        else{
            ans[step] = min(min_c,ans[step]);
        }
        for(int i = 0; i<color[u].size(); i++){
            int v = adj[u][i];
            int c = color[u][i];
            if(d[v]==d[u]-1 and !vis[v] and c==min_c){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}
int main(){
        _ios;

        while(cin>>n>>m){

                fill(vis),fill(ans);
                memset(d,-1,sizeof d);
                for(int i = 0; i<=n;i++){
                    adj[i].clear(), color[i].clear();
                }
                int a,b,c;
                for(int i = 0; i<m;i++){
                    cin >> a >> b >> c;
                    if(a==b)continue;
                    adj[a].pb(b), adj[b].pb(a);
                    color[a].pb(c), color[b].pb(c);
                }
                bfs1();
                bfs2();
                cout<<d[1]<<endl;
                cout<<ans[0];
                for(int i = 1; i<d[1];i++){
                    cout<<' '<<ans[i];
                }
                cout<<endl;
        }



return 0;
}



/*

4 6
1 2 1
1 3 2
3 4 3
2 3 1
2 4 4
3 1 1

*/
