#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

std::vector<int>prefix;
int total = 0;
void recur(vector<int>a,std::vector<int>per){
    if(per.size() == a.size()){
        for(auto x: per)cout << x << ' ';
            cout << endl;
        total++;
    }
    else{
        std::map<int, bool>exist;
        for(auto x:per){
            exist[x] = true;
        }
        for(int i = 0; i<a.size(); i++){
            if(!exist[a[i]]){
                std::vector<int>newPermut = per;
                newPermut.push_back(a[i]);
                recur(a,newPermut);
            }
        }
    }
}
void task(){
    // total possible permutation we know, N!
    // 3! = 1*2*3 = 6;
    // worked fine if n<10
    int n; cin >> n;
    std::vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    recur(a,std::vector<int>());
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
