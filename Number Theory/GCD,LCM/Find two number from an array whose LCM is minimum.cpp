//https://codeforces.com/contest/1154/problem/G

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
const int maxn = 10000005;
const int mod = 1000000007;

int n;
ll a[maxn];
std::vector<ll>adj[maxn];
std::vector<ll>freq(maxn, 0);

ll gcd(ll a,ll b){
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a, ll b){
    return a/ gcd(a,b)*b;
}
void task(){
    cin >> n;
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
        freq[ a[i] ]++;
        adj[ a[i] ].push_back(i);
    }
    ll x, y;

    ll mn_lcm = 1e14;
    for(ll g = 1; g <= mx; g++){
        std::vector<ll> v;
        v.clear();
        for(ll x = g; x <= mx; x+=g){
            if(freq[x])v.push_back(x);
            if(v.size() == 2)break;
            if(freq[x] > 1)v.push_back(x);
            if(v.size() == 2)break;
        }

        if(v.size() == 2){
            ll l = lcm(v[0], v[1]);
            if(l < mn_lcm){
                mn_lcm = l;
                if(v[0] != v[1]){
                    x = adj[ v[0] ][ 0 ];
                    y = adj[ v[1] ][ 0 ];
                }
                else{
                    x = adj[ v[0] ][ 0 ];
                    y = adj[ v[0] ][ 1 ];
                }
            }
        }
    }
    if(x > y)swap(x, y);
    cout << x <<' '<< y << endl;

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
