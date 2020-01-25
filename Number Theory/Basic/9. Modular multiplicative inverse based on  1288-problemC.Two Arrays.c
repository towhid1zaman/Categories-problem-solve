//1288/problem/C

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 1050;

ll fact[maxn];

ll bxp(ll x, ll n){
    if(n==-1)n = mod - 2; /// modular multiplicative inverse
    ll res = 1;
    while(n>0){
        if(n%2==1){
            res = res* x %mod;
        }
        x = x*x %mod;
        n = n /2;
    }
    return res;
}

void factorial(){
    fact[0] = 1;
    for(int i = 1; i<=maxn;i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
}

ll nCr(ll n, ll r){
    ll res = (((fact[n]*bxp(fact[r],-1) ) %mod ) * bxp(fact[n-r],-1) %mod);
    return res;
}

int main(){
        _ios;

        factorial();
        ll n,m;
        cin>>n>>m;

        ///Stars and Bars Theorem(Number Theory)
        ll star = 2*m;
        ll bar = n-1;
        ll ans  = nCr(star+bar,bar);
        cout<<ans<<endl;


return 0;
}






