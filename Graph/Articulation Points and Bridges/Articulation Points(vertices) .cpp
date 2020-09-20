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
const int maxn = 101010;

/*Articulation point using tarjan algorithm
 *some steps:
 *
 * Conditions for AP,
 * 1.if its root node then its must have at least two child
 * 2.visitTime of node <= lowtime of any adjecent node
 * 
 * lowTime Updation,
 * 1.When parent node in dfs traversal return from any child node,
 *	lowTime[parent] = min(lowTime[parent], lowTime[child])
 *
 * When Back edge exist,
 * 1.lowTime[current node] = min(lowTime[current node], VisitTime[that node]) 
 *
 *
 *
 */
int lowTime[maxn], visitTime[maxn], d, n, m;
vi adj[maxn];
set<int>st;

void RESET(){
	for(int i = 0; i<=n+5; i++){
		adj[i].clear();
		visitTime[i] = 0;
		lowTime[i] = 0;
	}
	st.clear();
}

void dfs(int u){
	lowTime[u] = visitTime[u] = ++d;
	int cnt = 0;
	for(auto v: adj[u]){
		if(!visitTime[v]){
			++cnt;
			dfs(v);
			lowTime[u] = min(lowTime[u], lowTime[v]);

			if(u==1 and cnt>1 or (u !=1 and visitTime[u]<=lowTime[v])){
				st.insert(u);
			}
		}
		else{
			// Visited , that means its a back edge
			lowTime[u] = min( lowTime[u], visitTime[v]);
		}
	}
}

void task(){
       cin >> n >> m;
       RESET();
       for(int i = 1; i<=m; i++){
       	int u, v; cin >> u >> v;
       	adj[u].pb(v);
       	adj[v].pb(u);
       }
       d = 0;
       dfs(1);

       cout << st.size() << endl;
       
}

int main(){
        //_
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1,tc=1; cin >> T;
        while(T--){
        	cout <<"Case "<<tc++<<": ";
            task();
        }
        
        
return 0;
}

/*
2

 
5 4

2 1

1 3

5 4

4 1


3 3

1 2

2 3

1 3

Case 1: 2
Case 2: 0

*/
