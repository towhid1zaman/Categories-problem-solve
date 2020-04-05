//Given n and r, in how many ways can r items be chosen from n items? (ncr = n!/ r! *(n-r)!

// </> : towhid1zaman

#include <bits/stdc++.h>
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
#define maxn 1000005
#define mod 1000003 // (int)1e9+7


ll fact[maxn];
ll ifact[maxn];
/*
    properties of mod inverse
      a^-1 % m
    =a^(m-2) % m
*/

/* Iterative Function to Calculate  (x^n)%mod in O(log n) */
ll bxp(ll x, ll n){
    ll res = 1;
    while(n){
        // if n is odd, multiply x with res
        if(n&1){
            res = (res*x)%mod;
        }
        //n/=2;
        x = (x*x)%mod;
        n >>=1;
    }
    return res;
}

ll ncr(ll n, ll r){
    if(r==0 || n==r)return 1LL;

    return ( ( ( fact[n]*ifact[n-r])%mod)*ifact[r])%mod;
}
//Pre calculation
void Fact(){
    fact[0] = 1;
    for(int i = 1; i<maxn; i++){
        fact[i] = (fact[i-1]*i)%mod;
        ifact[i]  = bxp(fact[i],mod-2);
    }
}

int main(){
        //_ios;

        Fact();
        int T,n,k;
        cin >> T;
        for(int cs  =1 ; cs<=T; cs++){
            cin >> n >> k;
            cout<<"Case "<<cs<<": "<<ncr(n,k)<<"\n";
        }


return 0;
}





