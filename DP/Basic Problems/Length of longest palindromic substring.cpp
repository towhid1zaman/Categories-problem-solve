/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*Given a string of length n
 *Find longest palindromic substring
 *n<=1000
 */
string s;
std::vector<vector<int>>dp(1000, vector<int>(1000, -1));
int go(int b, int e){
    if(b >= e)return 1;

    if(dp[b][e]!=-1)return dp[b][e];

    if(s[b] == s[e]){
        return dp[b][e] = go(b+1, e-1);
    }
    else return dp[b][e] = 0;
}
void task(){
    cin >> s;
    int ans = 0;
    for(int i = 0; i<(int)s.size(); i++){
        for(int j = i; j<(int)s.size(); j++){
            if(go(i, j)){
                ans = max(ans, j-i+1);
            }
        }
    }
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
