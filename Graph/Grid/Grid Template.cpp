//const int kx[8] = {-2, -2, -1, 1, -1, 1, 2, 2}, ky[8] = {1, -1, -2, -2, 2, 2, -1, 1}; //knight
//const int dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy8[8] = {0, 1, 0, -1, -1, 1, -1, 1}; //king
const int dx4[4] = {1,0,-1,0}, dy4[4] = {0,1,0,-1};
// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
const int dx8[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
const int dy8[8] = { 0, 1, 0,-1,  1, 1, -1, -1};
// Represents all moves of a knight in a chessboard
const int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
const int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};
bool gridCheck(int x, int y,int n, int m) { 
    return x >= 0 && y >= 0 && x < n && y < m; 
}
