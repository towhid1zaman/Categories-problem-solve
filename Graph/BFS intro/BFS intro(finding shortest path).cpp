
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const int maxn = 100100;

vector<int>adj[maxn];
int dist[maxn];
int par[maxn];
bool vis[maxn];

void bfs(int s){

    queue<int>q;
    q.push(s);
    vis[s] = 1;
    par[s] = s;
    dist[s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0; i<adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]){
                vis[v] = 1;
                par[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

}


int main(){
        _
        int node, edges; cin >> node >> edges;
        for(int i = 1; i<=edges; i++){
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int source; cin >> source;
        int target; cin >> target;
        bfs(source);
        vector<int>path;
        for(int i = target; i!=source; i = par[i]){
            path.push_back(i);
        }
        path.push_back(source);

        reverse(path.begin(), path.end());

        // printing all distance from source node
        for(int i = 1; i<=node; i++){
            cout<<"From " <<source<<" Node to "<<i << " Distance is "<<dist[i]<<endl;
        }cout<<endl;
        //printing path

        cout <<"path from source to distance "<<endl;
        for(int i = 0; i<path.size(); i++){
            cout<<path[i]<<' ';
        }cout<<endl;


return 0;
}
/*
10 11
1 2
1 7
1 6
2 3
3 4
4 6
4 5
7 8
8 9
9 6
9 10
1
10

expected output:
1 0
2 1
3 2
4 2
5 3
6 1
7 1
8 2
9 2
10 3
*/
