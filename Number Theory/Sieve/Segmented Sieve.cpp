// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

/// first generate prime using seive
vector<ll>prime;
void seive()
{
    bool primes[maxn+1];
    memset(primes,true, sizeof(primes));
    for(ll p = 2; p*p<=maxn;p++)
    {
        ///true means prime
        if(primes[p]==true)
        {
            for(int i = p*p;i<=maxn;i+=p)
            {
                primes[i] = false;
            }
        }
    }
    for(int i = 2; i<=maxn;i++){
            if(primes[i]==true){
                prime.push_back(i);
            }
        }
}
/// range
vector<ll>rPrime;  //final result
void segmented(ll L, ll R)
{
    bool isPrime[R-L+1];
    memset(isPrime,true,sizeof(isPrime));
    if(L==1){
        isPrime[0] = false;
    }
    for(ll i = 0;prime[i]*prime[i]<=R;i++){
        ll curPrime = prime[i];
        ll base = curPrime*curPrime;
        if(base<L)
        {
            base = ((L+curPrime-1)/curPrime)*curPrime;
        }
        for(ll j = base; j<=R;j+=curPrime){
            isPrime[j-L] = false;
        }
    }
    for(int i = 0;i<=R-L;i++)
    {
        if(isPrime[i]==true){
            rPrime.push_back(L+i);
        }
    }
}


int main(){
        _ios;

        seive();
        int l,r;
        cin >> l >> r;
        segmented(l,r);
        for(auto x: rPrime){
            cout<<x<<' ';
        }
        cout<<endl;


return 0;
}
