#include "bits/stdc++.h"
using namespace std;
#define ll long long

vector<int>adj[100000];
int vis[100000];
void dfs(int v){
    vis[v] = 1;
    cout<<v<<" ";
    for(auto child: adj[v]){
        if(vis[child]==0)
            dfs(child);
    }
}
int main()
{
    int node, edge;
    cin>>node>>edge;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i<=edge;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);


return 0;
}


/*

7 8
1 2
1 6
2 3
2 4
2 5
3 6
3 7
6 7

*/
