
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
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const int INF = 1e9 + 10;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

/*
    here i have given T test cases and, q queries , and an array of n size.
    each queries  i have given two number l,r; i have to findout gcd of excluding l....r

    approach:
    we can se that , int g1 = gcd(a[i]....,a[l])
                            int g2 = gcd(a[r]....a[n])
    this g1 and g2 nothing but prefix and suffix

    so we can solve it by prefix and suffix

    https://www.codechef.com/problems/GCDQ
*/
int ar[maxn];
int pre[maxn];
int suf[maxn];

int gcd(int a, int b){
    return( b==0 ? a: gcd(b,a%b));
}
int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            int  n,q; cin >> n >> q;
            for(int i = 1; i<=n; i++){
                cin >> ar[i];
            }
            pre[0] = suf[n+1] = 0;

            rep1(i,1,n){
                pre[i] = gcd(ar[i], pre[i-1]);
            }
            for(int i = n; i>=1; i--){
                suf[i]  = gcd(ar[i],suf[i+1]);
            }

            while(q--){
                int l,r; cin >> l >> r;
                cout<<gcd(pre[l-1], suf[r+1])<<endl;
            }
        }

return 0;
}






