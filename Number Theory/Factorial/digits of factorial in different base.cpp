#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

std::vector<double>ans;
int pre(){
    ans.resize(1000000);
    for(int i = 1; i<=1000000; i++){
        ans[i]=ans[i-1] + log10(i);
    }
}
void task(){
    int n, b; cin >> n >> b;
    int res = ans[n] / log10(b) + 1;
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pre();
    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
