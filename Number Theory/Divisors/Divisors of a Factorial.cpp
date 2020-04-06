
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back
#define inf (1<<29)

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

vector<ll>vec;
bool isPrime[1000101];
void sieve(){
    int MAX = 1000101, sq = sqrt(MAX);
    memset(isPrime,true, sizeof isPrime);
    for(int i = 4; i<=MAX; i+=2){
        isPrime[i] = 0;
    }
    for(int i = 3; i<=sq; i+=2){
        if(isPrime[i]){
            for(int j = i*i; j<=MAX; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    isPrime[1]=0;
    isPrime[0]=0;
    for(int p = 2; p<MAX; p++){
        if(isPrime[p])vec.pb(p);
    }
}

ll factorialDivisors(ll n){
    ll ans = 1;
    for(ll x : vec){
        ll p = x;
        ll exp = 0;
        while(p<=n){
            exp  = exp+(n/p);
            p = p*x;
        }
        ans = ans*(exp+1);
    }

    return ans;
}

int main(){
        _ios;

        sieve();
        ll n; cin >> n;
        cout<< factorialDivisors(n)<<endl;



return 0;
}

/*

let n = 4;
so factorial of 4 means ,
  4 = 4*3*2*1
     =24

now divisors of 24 are,
    24 = 1,2,3,4,6,8,12,24 = 8

*/
