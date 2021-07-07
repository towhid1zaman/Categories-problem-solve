/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*
    Given a Maze of n*m size, print all possible path to
    move from (0, 0) to (n-1, m-1) cell

    Move = right or down
*/
void print_path(int cur_i,int cur_j,int n,int m, string cur_path,int &tot_path){
    if(cur_i == n-1 and cur_j == m-1){
        tot_path++;
        cout << cur_path << endl;
        return;
    }
    if(cur_i > n or cur_j > m){
        return;
    }
    //right R
    print_path(cur_i, cur_j+1, n, m, cur_path+"R", tot_path);
    //down D
    print_path(cur_i+1, cur_j, n, m, cur_path+"D", tot_path);

}
void task(){
    int n, m; cin >> n >> m;
    int tot_path = 0;
    print_path(0, 0, n, m,"", tot_path);
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
