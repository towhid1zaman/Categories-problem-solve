/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*
    given an array of size n, thats have coins, and an amount W , 
    you have to tell how many ways you can make this amount W using anytime of this coins.
    
    ex:
    3 5
    1 2 5
    ans = 4
*/


int n, w;
int a[20004];
int dp[20004][20004];

int go(int pos, int weight){
    if(pos >= n){
        if(weight == 0)return 1;
        else return 0;
    }
    
    if(dp[pos][weight]!=-1)return dp[pos][weight];

    int take = 0, dont_take = 0;
    if(weight - a[pos] >= 0) take = go(pos, weight - a[pos]);
    dont_take = go(pos+1, weight);
    return dp[pos][weight] = take + dont_take;

}
void task(){
    cin >> n >> w;
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }    
    memset(dp, -1, sizeof(dp));
    int ans = go(0, w);
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
