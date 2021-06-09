/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*
 *given an array of n sizes, find max subsequence sum
 *don't take two consecutive elements
 *N<=100000
 */

int n;
int a[1000000];
std::vector<vector<int>>dp(100000, vector<int>(2, -1));

int go(int pos,int take){
    if(pos > n)return 0;
    
    if(dp[pos][take] != -1)return dp[pos][take];

    if(take == 1){
        return dp[pos][take] = go(pos+1, 0);// can't take, because previous element already taken
    }
    if(take == 0){
        return dp[pos][take] = max(go(pos+1, 1) + a[pos], go(pos+1, 0)); //take current position or dont take
    }
}
void task(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    int ans = go(0, 0); //position 0, and didn't take previous element
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
