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
const int maxn = 5e6 + 5;
const int mod = 1000000009;

/*
 *Polynomial hashing
 *Call Hash A(string , len, base, mod)
 */
struct Hash{
    int len, base; long long mod;
    string s;
    std::vector<int>p, h;
    // O(n)
    Hash(string s, int len, int base, int mod) : s(s), len(len), base(base), mod(mod) {
        p.resize(len + 1, 0); //base^i (mod mods)
        h.resize(len + 1, 0); // hash of prefix of length i
        p[0] = 1;
        for(int i = 1; i <= len; i++) {
            p[i] = (1LL * p[i - 1] * base) % mod;
            h[i] = (1LL * h[i - 1] * base + (int)s[i - 1]) % mod;
        }
    }
    /*
     *Returns hash of the substring of length len starting at pos. i
     *O(1)
     */
    int substr(int l, int r) {
        return (h[r] - (1LL * h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
    }
};
int dp[maxn];
void task(){
    string s; cin >> s;
    int n = (int)s.size();

    Hash A(s, n, 255, mod);
    reverse(all(s));
    Hash B(s, n, 255, mod);
    ll sum = 0;
    for(int i = 1; i<=n; i++){
        if(A.substr(1, i) == B.substr(n-i+1, n)){
            dp[i] = dp[i / 2] + 1;
            sum += dp[i];
        } 
    }
    cout << sum << endl;
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
