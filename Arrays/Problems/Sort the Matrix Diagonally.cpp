/*
*traverse diagonnaly and store value into a vector, sort the vector then
*simply put them them to matrix
*
*
*https://leetcode.com/problems/sort-the-matrix-diagonally/
*/
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        for(int col = 0; col< c; col++){
            vector<int>cur;
            int i = 0, j = col;
            while(i < r and j < c){
                cur.push_back(mat[i++][j++]);
            }
            sort(cur.begin(), cur.end());
            int pos = 0;
            i = 0, j = col;
            while(i < r and j < c){
                mat[i++][j++] = cur[pos++];
            }
        }
        for(int row = 0; row< r; row++){
            vector<int>cur;
            int i = row, j = 0;
            while(i < r and j < c){
                cur.push_back(mat[i++][j++]);
            }
            sort(cur.begin(), cur.end());
            int pos = 0;
            i = row, j = 0;
            while(i < r and j < c){
                mat[i++][j++] = cur[pos++];
            }
        }
        return mat;
    }
};
