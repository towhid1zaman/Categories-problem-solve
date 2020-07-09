// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef vector<pii>vip;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 500005;

vll prime;
bitset<100000000>bs;

void sieve(){
        bs.set();
        prime.pb(2LL);
        for(ll i = 3; i<=100000000; i+=2){
            if(bs[i]){
                prime.pb(i);
                for(ll j = i*i; j<=100000000; j+=i+i){
                    bs[j] = 0;
                }
            }
        }
}

ll summation(ll n){
    ll oo=n;
    ll ans = 1;
    for(int i = 0; i<prime.size() and (ll)prime[i]*prime[i]<=n; i++){
        int cnt = 0;
        ll sum = 1, pw = 1;
        while(n%prime[i]==0){
            pw*=prime[i];
            sum+=pw;
            cnt++;
            n/=prime[i];
        }
        if(cnt>0) ans*=sum;
    }
    if(n>1)ans*=n+1;
    return ans - oo; //less than n
}

void task(){
 ll n; cin >> n;
 ll ans = summation(n);
 cout << ans << endl;
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif
        sieve();
        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
return 0;
}
/// Time  Complexity: O(n) precalculation + O(log n) query
