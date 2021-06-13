//https://codeforces.com/contest/14/problem/D

/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

const double pi = acos(-1.0);
const int maxn = 2006;
const int mod = 1000000007;

std::vector<int>adj[maxn];
std::vector< pair<int, int> > edges;

int mxNode = -1, mxDist = -1;
int cur = 0;
void dfs(int u, int p, int cost){
    if(cost > mxDist){
        mxDist = cost;
        mxNode = u;
    }
    for(int i = 0; i<adj[u].size(); i++){
        int v = adj[u][i];
        if(v == p or v == cur){
            continue;
        }
        dfs(v, u, cost+1);
    }
}

int longestpath(int u){
    mxNode = mxDist = -1;
    dfs(u, -1, 0);
    int max_node = mxNode;
    mxNode = mxDist = -1;
    dfs(max_node, -1, 0);
    return mxDist;
}

void task(){
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.emplace_back(a, b);
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        int a = edges[i].first;
        int b = edges[i].second;
        cur = b;
        int cost1 = longestpath(a);
        cur = a;
        int cost2 = longestpath(b);
        ans = max(ans, 1ll*cost1*cost2);
    }

    cout << ans << endl;

}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
