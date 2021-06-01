/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

const double pi = acos(-1.0);
const int maxn = 200005;
const int mod = 1000000007;

std::vector<ll>ans;
ll a, b;
void dfs(ll x){
    if(x==b){
        cout << "YES"<<endl;
        cout <<ans.size() << endl;
        for(auto c:ans)cout << c<<' ';
        cout << endl;
        exit(0);
    }
    else{
        if(x>b)return;
        ans.push_back(x*10+1);
        dfs(x*10 + 1);
        ans.pop_back();

        ans.push_back(x*2);
        dfs(x*2);
        ans.pop_back();
    }
}
void task(){
    cin >> a >> b;
    ans.push_back(a);
    dfs(a);
    cout << "NO" << endl;
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
