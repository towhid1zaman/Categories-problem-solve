//https://www.spoj.com/problems/EZDIJKST/

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
const int maxn = 100006;
const int mod = 1000000007;

namespace Dijkstra_Path{
    const int range = 16008;
    const long long inf = 1e14;
    typedef std::pair<long long, long long> pll;
    long long dist[range];
    int par[range];
    std::vector< std::pair<int,int> > adj[range];
    
    void clear(int n){
        for(int i = 0; i <= n; i++){
            dist[i] = inf;
            par[i] = 0;
            adj[i].clear();
        }
    }
    
    void dijkstra(int s, int n){
        priority_queue<pll> Q; // greater value first, (we passed -ve value) 
        dist[s] = 0;
        Q.push({0, s});

        while(!Q.empty()){
            long long u = Q.top().second;
            if(u==n)break;
            Q.pop();
            for(auto v : adj[u]){
                if(v.second + dist[u] < dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    Q.push( { -dist[v.first], v.first } );
                    par[v.first] = u;
                }
            }
        }
    }

    bool is_reached(int n){
        return dist[n] == inf;
    }
    
    std::vector<int> path_print(int s, int n){
        int u = n;
        std::vector<int> path;
        path.push_back(n);
        while ( n != s ) {
            n = par[n];
            path.push_back (n);
        }
        reverse(path.begin(), path.end());
        return path;
    }
    //check range,clear
}using namespace Dijkstra_Path;

void task(){
    int n, m; cin >> n >> m;
    clear(n);
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back( {v, w} );
       // adj[v].push_back( {u, w} );
    }
    int a, b; cin >> a >> b;
    dijkstra(a, b);
    if(is_reached(b)){
        cout << "NO" << endl;
        return;
    }
    cout << dist[b] << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<":" << endl;
        task();
    }
      
return 0;
}
