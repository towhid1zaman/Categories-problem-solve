const int kx[8]={-2,-2,-1,1,-1,1,2,2};
const int ky[8]={1,-1,-2,-2,2,2,-1,1};
const int dx8[8] = {0,0,1,1,1,-1,-1,-1};
const int dy8[8] = {1,-1,1,-1,0,0,-1,1};
const int dx4[4] = {0,0,1,-1}, dy4[4] = {1,-1,0,0};
bool gridCheck(int x, int y,int n, int m) { 
    return x >= 0 && y >= 0 && x < n && y < m; 
}
