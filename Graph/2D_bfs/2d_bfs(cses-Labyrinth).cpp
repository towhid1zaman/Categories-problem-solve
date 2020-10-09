//https://cses.fi/problemset/task/1193

// </> : towhid1zaman

 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1002;

//dist calculate lavels, and ways calculate number of ways of same shortest path from source to any other node

int n, m, sx, sy, tx, ty;
std::vector<pair<int,int>>par[maxn][maxn];
int visit[maxn][maxn], dist[maxn][maxn], ways[maxn][maxn];
string cell[maxn];
char Path[maxn][maxn];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
string ds="RLDU"; //record path

bool gridCheck(int x, int y) { 
    return x >= 0 && y >= 0 && x < n && y < m; 
}

void RESET(){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){	
			visit[i][j] = 0;
			dist[i][j] = 0;
			ways[i][j] = 0;
			par[i][j].clear();
		}
	}
	
}

void bfs(int ii, int jj){
	queue<pii>q;
	q.push({ii,jj});
	visit[ii][jj] = 1;
	dist[ii][jj] = 0, ways[ii][jj] = 1;
	par[ii][jj].push_back({0,0});

	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i = 0; i<4; i++){
			int xx = x + dx[i], yy = y + dy[i];
			
			if(!gridCheck(xx, yy))continue;
			if(cell[xx][yy] == '#')continue;
			
			if(!visit[xx][yy]){
				visit[xx][yy] = 1;
				dist[xx][yy]=dist[x][y]+1, ways[xx][yy]+=ways[x][y];
				q.push({xx,yy});
				par[xx][yy].push_back({x,y});
				Path[xx][yy] = ds[i];
			}
			else{
				if(dist[x][y] + 1 == dist[xx][yy]){
					ways[xx][yy]+=ways[x][y];
				}
			}

		}
	}
}

void path_print(){
	if(!visit[tx][ty]){
		cout << "NO" << endl;
	}
	else{
		string ansPath="";
		cout << "YES" << endl;
		pii start = make_pair(sx,sy);
		pii end = make_pair(tx,ty);

		while(end != start){
			ansPath += Path[end.first][end.second];
			end = par[end.first][end.second][0];
		}
		reverse(ansPath.begin(), ansPath.end());
		cout << ansPath.size() << endl;
		cout << ansPath << endl;
	}
}
void task(){
	RESET();
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		cin >> cell[i];
		for(int j = 0; j<m; j++){
			if(cell[i][j] == 'A')sx = i, sy = j;
			else if(cell[i][j] == 'B')tx = i, ty = j;
		}
	}

	bfs(sx,sy);
	path_print();
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


