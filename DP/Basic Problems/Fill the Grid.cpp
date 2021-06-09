/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*
 *given 2xN grid, How many ways we can fill the whole grid with tiles.
 *gievn, 2x1 and 2x2 tiles, and no rotation allowed  
 *N<=100000
 */

std::vector<int>dp(100000, -1);
int go(int n){
    //base case
    if(n==1)return 1; //2x1 tiles
    if(n==2)return 2; //2x2 tiles can fill only in 2 ways
    //memoization
    if(dp[n]!=-1)return dp[n];

    //transition
                 //2x1 and 2x2 moves
    return dp[n] = go(n-1) + go(n-2);
}
void task(){
    int n; cin >> n;
    int ans = go(n); //we dont need 2 state, because 2 fixed(2xN)
    cout << ans << endl;
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
