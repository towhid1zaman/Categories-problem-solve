
int n,m;
int res[maxn];
int Nu[maxn],Nv[maxn],t[maxn];
int pos[maxn];
vector<int>adj[maxn];
vector<int>sorted;

bool topoSort(int n){
    sorted.clear();
    queue<int>q;
    vector<int>indegree(n+2,0);
    for(int i = 1; i<=n; i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }
    for(int i = 1; i<=n; i++){
        if(!indegree[i]){
            q.push(i);
        }
    }
    int indx = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        sorted.push_back(u);
        indx++;
        pos[u]=indx;
        for(auto v: adj[u]){
            indegree[v]--;
            if(!indegree[v]){
                q.push(v);
            }
        }
    }
    return (sorted.size()==n); // returns 1 if there exist a topo, returns 0 if exists a cycle

}
