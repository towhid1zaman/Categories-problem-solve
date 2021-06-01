/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/

#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


/*
    Given a string generate all possible permutation
    if string size is n, then possible permutations
    is n!
    worked fine if n < 10
*/
std::vector<string>ans;
void permutation(string s, int l, int r){
    if(l == r){
        ans.push_back(s);
        return;
    }
    for(int i = l; i<=r; i++){
        swap(s[l], s[i]);
        permutation(s, l+1, r);
        swap(s[l], s[i]);
    }
}

void task(){
    string s; cin >> s;
    int n = s.size();
    permutation(s, 0, n-1);
    cout << ans.size() << endl;
    for(auto c: ans){
        cout << c << endl;
    }
    cout << endl;
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
