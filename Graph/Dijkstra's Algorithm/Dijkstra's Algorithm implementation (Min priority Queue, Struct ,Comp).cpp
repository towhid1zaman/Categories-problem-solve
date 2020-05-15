
//Dijkstra O(V + ElogV) implementation using min priority queue

// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) (v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;


struct node{
    int val;
    int cost;
};
vector<node>adj[maxn];
int dis[maxn];
bool vis[maxn];
/// priority queue purpose
struct comp{
    bool operator()(node x ,  node y){
        //The maximum cost will be popped last
        if(x.cost > y.cost)return true;
        return false;
    }
};

void Dijkstra(int source){
    priority_queue<node,vector<node>, comp> pq;
    pq.push({source,0});

    while(!pq.empty()){
        node current  = pq.top();
        pq.pop();

        int val = current.val;
        int cost = current.cost;

        if(vis[val]==1)continue; // if visited, we don't work with this node

        dis[val] = cost; // final cost
        vis[val] = 1; // mark as visited

        for(int i = 0; i<adj[val].size(); i++){
            int next = adj[val][i].val;
            int nextCost = adj[val][i].cost;

            if(vis[next]==0){
                pq.push({next, cost+nextCost});
            }
        }
    }
}

int main(){
        _
        int nodes,edges; cin >> nodes >> edges;
        for(int i = 1; i<=edges; i++){
            int u,v,w; cin >> u >> v >> w;
            adj[u].push_back({v,w});
        }

        int source; cin >> source;

        Dijkstra(source);

        for(int i = 1; i<=nodes; i++){
            cout<<source<<" to node "<<i<<" distance: "<<dis[i]<<endl;
        }


return 0;
}

/*
input:
5 6
1 2 2
1 3 1
1 4 3
2 3 1
4 5 2
5 3 5
1

output:
1 to node 1 distance: 0
1 to node 2 distance: 2
1 to node 3 distance: 1
1 to node 4 distance: 3
1 to node 5 distance: 5

*/
