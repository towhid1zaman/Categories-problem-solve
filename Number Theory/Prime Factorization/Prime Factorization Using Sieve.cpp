
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
const int inf = 100006;// (int)3e18;
const int maxn = 10000040;
 
vector<int>prime;
bool isPrime[10000040];
void sieve(){
    int N = 10000040, sq = sqrt(N);
    memset(isPrime, true, sizeof isPrime);
    for(int i = 4; i<=N; i+=2){
        isPrime[i] = false;
    }
    for(int i = 3; i<=sq; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j<=N; j+=i){
                isPrime [j] = false;
            }
        }
    }
    prime.pb(2);
    for(int i = 3; i<=N; i+=2){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
}
void task(){
 int n; cin >> n;
 int ev=0,od=0;
 for(int i = 0; prime[i]<=sqrt(n); i++){
    if(n%prime[i]==0){
        int cnt = 0;
        while(n%prime[i]==0){
            n/=prime[i];
            cnt++;
        }
        if(cnt%2)od++;
        else if(cnt)ev++;
    }
 }
 if(n>1)od++;
 if(ev>od)cout << "Psycho Number"<< endl;
 else cout << "Ordinary Number" << endl;

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
