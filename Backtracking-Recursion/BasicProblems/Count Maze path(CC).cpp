/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

//https://www.codechef.com/problems/BPHC03

//Backtracking

bool ok(int n, int i, int j, std::vector<vector<bool>>&visited){
    return i>=0 and j>=0 and i<n and j<n and visited[i][j]==false;
}

int tot_path = 0;

void go(int i, int j, int n,std::vector<vector<int>>&grid, std::vector<vector<bool>>&visited){
    if(i==n-1 and j==n-1){
        tot_path++;
        return;
    }
    if(!ok(n, i, j, visited)){
        return;
    }

    visited[i][j] = 1;

    if(i+1<n and grid[i+1][j] == 0) go(i+1, j, n, grid, visited); //down
    if(i-1>=0 and grid[i-1][j] == 0)go(i-1, j, n, grid, visited); //up
    if(j+1<n and grid[i][j+1] == 0) go(i, j+1, n, grid, visited); // right
    if(j-1>=0 and grid[i][j-1] == 0)go(i, j-1, n, grid, visited); //left

    //back his original form, backtrack

    visited[i][j] = 0;
}

void task(){
    int n; cin >> n;
    std::vector<vector<int>>grid(n, vector<int>(n,{}));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    std::vector<vector<bool>>visited(n, vector<bool>(n, false));
    go(0,0, n, grid, visited);
    cout << tot_path << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
