//https://codeforces.com/contest/1133/problem/B

#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;


void task(){
    int n, k; cin >> n >> k;
    std::vector<int> v(n);
    std::map<int, int> mp;
    for(int i = 0; i<n; i++){
        cin >> v[i];
        v[i]%=k;
        mp[ v[i] ]++;
    }
    int cnt = 0;
    for(int i = 0; i<n; i++){
        if(!mp[ v[i] ])continue;
        int needs = k - v[i];
        needs%=k;
        if(mp[needs]){
            if(needs != v[i] or (needs==v[i] and mp[needs] > 1)){
                cout << v[i] << ' '<<needs<<endl;
                mp[needs]--;
                mp[v[i]]--;
                cnt++;
            }
        }
    }
    for(int c: v)cout << c <<' ';cout << endl;
    cout << cnt << endl;
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
