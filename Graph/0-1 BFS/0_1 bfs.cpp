
// </> : towhid1zaman
#include "bits/stdc++.h"
using namespace std;

const int maxn = 10005;

int n, m;
std::vector<pair<int,int>>adj[maxn];
std::vector<int>dist;

void bfs_01(int s){
	dist.resize(n+1,1e9);
	deque<int>q;
	q.push_back(s);
	dist[s] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop_front();
		for(auto p : adj[u]){
			int v = p.first;
			int c = p.second;

			if(dist[v] > dist[u] + c){
				dist[v] = dist[u] + c;
				if(c==1)q.push_back(v);
				else q.push_front(v);
			}
		}
	}
}

void task(){
	cin >> n >> m;
	
	for(int i = 1; i<=m; i++){
		int u,v,c;
		cin >> u >> v >> c;
		adj[u].emplace_back(v,c);
		adj[v].emplace_back(u,c);
	}

	int source; cin >> source;
	bfs_01(source);
	
	for(int i = 1; i<=n;i++){
		cout << dist[i]<<' ';
	}
	cout << endl;
}

int main(){
 
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1,tc = 1; //cin >> T;
        while(T--){
            //cout <<"Case "<<tc++<<": ";
            task();
        }
        
        
return 0;
}


/*
i/p
6 6
1 2 0
1 3 1
2 6 1
2 4 0
3 4 1
4 5 1
1

o/p
0 0 1 0 1 1 

*/


/*
p: https://www.codechef.com/problems/REVERSE
s:https://www.codechef.com/viewsolution/38323272
