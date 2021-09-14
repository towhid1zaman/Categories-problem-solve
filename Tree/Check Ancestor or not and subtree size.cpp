int sec = 0;
std::vector<int> edges[100], in(100, 0), out(100, 0);
void dfs(int root, int parent){
    in[root] = ++sec;
    for(auto x: edges[root]){
        if(x!=parent){
            dfs(x, root);
        }
    }
    out[root] = ++sec;
}
void task(){
    int n, m; cin >> n >> m;

    for(int i = 1; i<=m; i++){
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, -1);
    //check whether u is ancestor of v or not.
    int u, v; cin >> u >> v;
    if(in[u] > in[v] and out[u] < out[v]){
        cout <<v <<" is Ancestor of node "<<u << endl;
    }
    else cout <<v <<" isn't Ancestor of node "<<u << endl;
    //subtree size
    int sub_size = (out[v] - in[v] + 1)/2;
    cout << "Subtree size of node "<<v <<" is "<<sub_size<<endl;
}
