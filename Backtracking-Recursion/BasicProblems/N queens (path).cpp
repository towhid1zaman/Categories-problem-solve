/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

//Backtracking

class Solution {
public:
    //Backtracking

    bool ok(int n, int row, int col, std::vector<vector<int>>&grid){
       //check up;
       for(int i = row; i>=0; i--){
        if(grid[i][col] == 1)return false;
       }

       //check down
       for(int i = row; i<n; i++){
        if(grid[i][col] == 1)return false;
       }

       //check left
       for(int i = col; i<n; i++){
        if(grid[row][i] == 1)return false;
       }

       //check right
       for(int i = col; i>=0; i--){
        if(grid[row][i] == 1)return false;
       }

       //check upper left diagonal
       for(int i = row, j = col; i>=0 and j >=0; i--, j--){
        if(grid[i][j] == 1)return false;
       }

       //check upper right diagonal
       for(int i = row, j = col; i>=0 and j < n; i--, j++){
        if(grid[i][j] == 1)return false;
       }

       //check lower left diagonal
       for(int i = row, j = col; i<n and j >= 0; i++, j--){
        if(grid[i][j] == 1)return false;
       }

       //check lower right diagonal
       for(int i = row, j = col; i<n and j<n; i++, j++){
        if(grid[i][j] == 1)return false;
       }

       return true;
    }

    int tot_path = 0;
    std::vector< std::vector<string> > paths;
    void go(int row,int n,std::vector<vector<int>>&grid){
        if(row >= n){
            vector<string>v;
            for(int i = 0; i<n; i++){
                string a;
                for(int j = 0; j<n; j++){
                    if(grid[i][j])a.push_back('Q');
                    else a.push_back('.');
                }
                v.push_back(a);
            }
            paths.push_back(v);
            tot_path++;
            return;
        }
        for(int i = 0; i<n; i++){
            if(ok(n, row, i, grid)){
                grid[row][i] = 1;
                go(row+1,n, grid);
                grid[row][i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        std::vector<vector<int>>grid(n, vector<int>(n, 0));
        go(0, n, grid);
        return paths;
    }
};

void task(){
    int n; cin >> n;
    Solution a;
    a.solveNQueens(n);
    cout << a.tot_path << endl;

    int x = a.paths.size();
    int y = a.paths[0].size();
    for(int i = 0; i<x; i++){
        for(int j = 0; j<y; j++){
            cout << a.paths[i][j];
            if(j < y-1)cout <<", ";
        }
        cout << endl;
    }

    /*
    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
    Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
    */
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
