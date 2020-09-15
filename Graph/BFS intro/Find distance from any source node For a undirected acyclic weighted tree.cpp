
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define deb(x) cout<<#x <<"="<<x<<endl;
#define present(v,x) ((v).find(x)!=(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sp(k) cout<<setprecision(k)<<fixed;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()


#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)

#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define yn(k) if(k)puts("YES");else puts("NO");

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 30000;

/*
 *
 */
int n, dist[maxn];
bool vis[maxn];
vi adj[maxn], cost[maxn];

void bfs(int s){
	for(int i=0;i<n;i++){
		vis[i]=0; 
		dist[i]=inf; 
	}
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	dist[s] = 0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i=0;i<adj[p].size();i++){
			int v = adj[p][i];
			if(!vis[v]){
				vis[v] = 1;
				dist[v] = dist[p]+cost[p][i];
				q.push(v);
			}
		}

	}
}
int cs = 1;
void task(){
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb(v);
		adj[v].pb(u);

		cost[u].pb(w);
		cost[v].pb(w);
	}

	bfs(0);
	int mx_node;
	int mx_dist = 0;

	for(int i = 0; i<n; i++){
		if(dist[i]>mx_dist)mx_node = i,mx_dist = dist[i];
	}

	bfs(mx_node);

	mx_dist = 0;
	for(int i = 0; i<n; i++){
		if(dist[i]>mx_dist){
			mx_dist = dist[i];
		}
	}
	cout <<"Case "<<cs++<<": "<<mx_dist<<endl;
	for(int i=0;i<n;i++){
		adj[i].clear();
		cost[i].clear(); 
	}
}

int main(){
        
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
        
return 0;
}


