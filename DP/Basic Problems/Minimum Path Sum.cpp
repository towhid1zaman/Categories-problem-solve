/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
which minimizes the sum of all numbers along its path.

https://leetcode.com/problems/minimum-path-sum/
*/

/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int dp[n][m]; //dp(i, j) tell minimum cost to reach this cell from start
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i<n; i++){
            for(int j =0; j < m; j++){
                if(i == 0 and j == 0){
                    dp[i][j] = grid[i][j];
                }
                else if(i == 0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else{
                    dp[i][j] = min( dp[i-1][j] , dp[i][j-1] ) + grid[i][j];
                } 
            }
        } 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout << dp[i][j] <<' ';
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }
};
void task(){
    Solution a;
    int n, m; cin >> n >> m;
    std::vector<vector<int>>grid;
    for(int i = 0; i<n; i++){
        std::vector<int> v;
        for(int j = 0; j < m; j++){
            int x; cin >> x;
            v.push_back(x);
        }
        grid.push_back(v);
    }
    cout << a.minPathSum(grid) << endl;
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
