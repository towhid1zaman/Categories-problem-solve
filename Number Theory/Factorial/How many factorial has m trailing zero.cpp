#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

std::vector<int> v[maxn];
void zero(){
    int d = 5;
    for(int i = 5; ; i++){
        int n = i, p = 0;
        while(n/d){
            p+=n/d;
            n/=d;
        }
        if(p>100000)break;
        v[p].push_back(i);
    }
}
void task(){
    zero();

    ll m; cin >> m;
    if(v[m].size()){
        cout << v[m].size() << endl;
        for(int i = 0; i<v[m].size(); i++){
            cout << v[m][i]<<' ';
        }
        cout << endl;
    }
    else cout << 0 << endl;
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
