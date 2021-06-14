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
