
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

ll triangle(ll a, ll b){
    return (a+b+1) * (b-a)/2;
}
//sum of divisors between a to b
ll divSum(ll a, ll b){
        ll n = sqrt(b);
        ll sum = 0;
        for(ll i = 1; i<=n; i++){
            sum+=i*(b/i - a/i) + triangle(max(n,a/i),max(n,b/i));
        }
        return sum;
}

int main(){
        _ios;

        ll a, b; cin >> a >> b;
        ll ans = divSum(a-1,b);
        cout<<ans<<endl;


return 0;
}
/*

let a = 1, b = 4

so all divisors from a to b,
1 = 1
2 = 1,2
3 = 1,3
4 = 1,2,4

total_sum_of_divisors = 1+1+2+1+3+1+2+4 = 15

*/



