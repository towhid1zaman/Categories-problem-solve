/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ll;
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

void task(){
    ll fact[22] = {1};
    for(int i = 1; i<20; i++){
      fact[i] = fact[i-1]*i;
    }

    ll n;
    while(cin >> n and n){
      ll cnt[11] = {0};
      ll sum = 0;
      for(ll i = 0; i<n; i++){
        ll a; cin >> a;
        cnt[ a ]++;
        sum+=a;
      }

      ll C = fact[n], cur = 0, dec = 1;
      for(ll i = 0; i<10; i++){
        C/=fact[ cnt[i] ];
      }

      for(ll i = 0; i<n; i++){
        cur+=dec;
        dec*=10;
      }

      ll ans = ( ((C*sum)/n) * cur );
      cout << ans << endl;
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
