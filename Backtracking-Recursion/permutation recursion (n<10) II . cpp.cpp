#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

int total;
void recur(int n, std::vector<int>per){
    if(per.size() == n){
        for(auto x: per)cout << x <<' ';cout << endl;
        total++;
    }
    else{
        std::map<int, bool>exist;
        for(auto x: per){
            exist[x] = true;
        }

        for(int i =1; i<=n; i++){
            if(!exist[i]){
                per.push_back(i);
                recur(n, per);
                per.pop_back();
            }
        }
    }
}
void task(){
    // total possible permutation we know, N!
    // 3! = 1*2*3 = 6;
    // worked fine if n<10
    int n; cin >> n;
    recur(n, std::vector<int>());
    cout << total << endl;
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
