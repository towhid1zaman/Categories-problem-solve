//https://codeforces.com/contest/7/problem/C

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
        
namespace Math_Basic{
    template <class T> T abs(T x){
        return x > 0 ? x : -x;
    }
    template <class T> T sqr(T x){
        return x * x;
    }
    ll Ceil(ll n, ll m){
        return (n+m-1)/m;
    }
    ll gcd(ll a,ll b){
        return b ? gcd(b,a%b) : a;
    }
    ll lcm(ll a, ll b){
        return a/ gcd(a,b)*b;
    }
    ll gcdExtended(ll a,ll b,ll &x,ll &y){
        if(b==0){
            x=1ll,y=0ll;
            return a;
        }
        ll g = gcdExtended(b,a%b,y,x);
        y-=a/b*x;
        return g;
    }
    ll bigpow(ll a, ll e){
        ll ret = 1LL; ll aa = (ll)a;
        while (e){
            if (e&1) {
                ret *= aa;
                e--;
            }
            aa *= aa;e /= 2;
        }
        return ret;
    }   
}using namespace Math_Basic;

void task(){
    ll a, b, c, x, y, g;
    cin >> a >> b >> c;
    g = gcdExtended(a, b,x, y);
    if(c%g){
        cout << -1 << endl;
        return;
    }
    ll X = (-c/g) * x;
    ll Y = (-c/g) * y;
    cout << X <<' '<< Y << endl;
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
