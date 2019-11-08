#include "bits/stdc++.h"
using namespace std;
#define ll long long
vector<int>edgelist[200005];
int d[200005];
void bfs(int s){
    memset(d,-1,sizeof(d));
    d[s] = 0;
    queue<int>q;
    q.push(s);
    while(q.size()>0){
        int u = q.front();
        q.pop();
        for(int i = 0; i<edgelist[u].size();i++){
            int v = edgelist[u][i];
            if(d[v]==-1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

}
int main()
{
    int edge,node;
    cin>>edge>>node;
    for(int i = 1;i<=edge;i++)
    {
        int u,v;
        cin>>u>>v;
        edgelist[u].push_back(v);
        edgelist[v].push_back(u); /// not need if directed
        /// because of undirected graph
    }
    int source;
    cin>>source;
    bfs(source);

    cout<<"Shortest Path From source to every node: "<<endl;
    for(int i = 1; i<=node;i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

return 0;
}

/*
8 7
1 2
1 6
2 3
2 4
2 5
3 6
3 7
6 7
3

*/

