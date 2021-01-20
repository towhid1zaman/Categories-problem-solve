#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

int remainder(string s, int y){
    int n = s.size();
    int rem = 0;
    for(int i = 0; i<n; i++){
        rem = rem*10 + s[i] - '0';
        rem%=y;
    }
    return rem;
}
void task(){
    string a; int b; cin >> a >> b;
    cout << remainder(a, b) << endl;   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
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

/*
121 % 9 = 4
*/
