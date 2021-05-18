
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
const int maxn = 12345678;
const int mod = 1000000007;

int d[maxn]{}, frq[maxn]{};
int fact(int n, int l){
    int carry = 0, k = 0, now;
    for(int i = 0;i<l; i++){
      now = d[i] * n + carry;
      d[k++] = now%10;
      carry = now/10;
    }

    while(carry){
      d[k++] = carry%10;
      carry/=10;
    }
    return k;
}

void solve(int n){
    fill(frq, frq+maxn, 0);
    //fill(d, d+maxn, 0);
    d[0] = 1;
    int len = 1;
    for(int i = 2; i<=n; i++){
      len = fact(i, len);
    }
    string ans ="";
    for(int i = 0; i<len; i++){
      ans+=d[i] + '0';
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    
}

void task(){
    int n;
    while(cin >> n and n){
      solve(n);
    }
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
