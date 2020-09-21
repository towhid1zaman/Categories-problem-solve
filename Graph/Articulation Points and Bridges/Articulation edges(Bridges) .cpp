
// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
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
const int maxn = 10011;

/*
 *
 */
int lowTime[maxn], visitTime[maxn], vis[maxn], d, n, m;
vi adj[maxn];
set<pii>st;

void RESET(){
	for(int i = 0; i<=n+5; i++){
		adj[i].clear();
		visitTime[i] = 0;
		lowTime[i] = 0;
		vis[i] = 0;
	}
	st.clear();
}

void dfs(int v, int p=-1){
	vis[v] = 1;
	lowTime[v] = visitTime[v] = d++;
	int cnt = 0;
	for(auto to: adj[v]){
		if(to==p)continue;
		if(vis[to]){
			lowTime[v] = min( lowTime[v], visitTime[to]);
		}
		else{
			dfs(to, v);
			lowTime[v] = min(lowTime[v], lowTime[to]);
			if(lowTime[to] > visitTime[v]){
				st.insert({min(v,to), max(v,to)});
			}
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
	for(int i = 1; i<=n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	if(st.size()==0){
		cout <<"Sin bloqueos"<<endl;
		return;
	}
	cout << st.size()<<endl;
	for(auto x:st){
		cout << x.first<<" "<<x.second << endl;
	}
}

int main(){
        //_
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1,tc = 1; cin >> T;
        while(T--){
            cout <<"Caso #"<<tc++<<endl;
            task();
        }
        
        
return 0;
}
