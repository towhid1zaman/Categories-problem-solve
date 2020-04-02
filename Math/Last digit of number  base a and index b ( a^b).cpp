
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

You are given two integer numbers:
the base a (0 <= a <= 20) and the index b (0 <= b <= 2,147,483,000),
a and b both are not 0. You have to find the last digit of a^b.
*/

void solve(){
    ll a,b,c,d;
    cin>>a>>b;
        c = a%10;
        d = b%4;
        if(b==0)
        {
            cout<<1<<endl;
        }
        else if(c==1 or c==5 or c==6)
        {
            cout<<c<<endl;
        }
        else if(d==1){
            cout<<c<<endl;
        }
        else if(d==2)
        {
            cout<<(c*c)%10<<endl;
        }
        else if(d==3)
        {
            cout<<(c*c*c)%10<<endl;
        }
        else if(d==0)
        {
            cout<<(c*c*c*c)%10<<endl;
        }
}
int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            solve();
        }


return 0;
}






