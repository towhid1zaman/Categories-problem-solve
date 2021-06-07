//https://codeforces.com/contest/514/problem/C

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

/*
 *Polynomial hashing
 *Call Hash A(string , len, base, mod)
 */
struct Hash{
    int len, base; long long mod;
    string s;
    std::vector<int>p, h;
    //Hash(){}
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


void task(){
    int n, m; cin >> n >> m;
    std::map<pair<int, int>, int> mp[3]; // abc
    for(int i = 0; i<n; i++){
        string s; cin >> s;
        int len = (int)s.size();
        Hash A(s, len, 571, 1e9 + 9);

        for(int j = 1; j <= len; j++){
            int x, y;
            if(j == 1){
                x = 0;
                y = A.substr(2, len);
            }
            else if(j == len){
                x = A.substr(1, len-1);
                y = 0;
            }
            else{
                x = A.substr(1, j-1);
                y = A.substr(j+1, len);
            }
            mp[s[j-1] - 'a'][{x, y}] = 1;
        }
    }

    for(int i = 0; i < m; i++){
        string s; cin >> s;
        int len = (int)s.size();
        Hash B(s, len, 571, 1e9 + 9);
        bool ok = 0;
        for(int j = 1; j <= len; j++){
            int x, y;
            if(j == 1){
                x = 0;
                y = B.substr(2, len);
            }
            else if(j == len){
                x = B.substr(1, len-1);
                y = 0;
            }
            else{
                x = B.substr(1, j-1);
                y = B.substr(j+1, len);
            }
            int a, b, c;
            c = s[j-1] - 'a';
            if(c == 0){
                a = 1;
                b = 2;
            }
            else if(c == 1){
                a = 0, b = 2;
            }         
            else a = 0, b = 1;

            ok = mp[a][{x,y}] or mp[b][{x,y}];
            if(ok)break;
        }

        cout << (ok ? "YES":"NO") << endl;
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
