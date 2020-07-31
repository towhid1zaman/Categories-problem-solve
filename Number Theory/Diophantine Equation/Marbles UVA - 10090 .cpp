
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
const int maxn = 200005;

ll d,x,y;
void EEA(ll a, ll b){
   if(b==0){
    d = a;
    x = 1;
    y = 0;
   }
   else{
    EEA(b,a%b);
    ll temp = x;
    x = y;
    y = temp - (a/b)*y;
   }
}

void task(){
 	ll n;
 	while(cin >> n and n){
 		ll c1,n1,c2,n2;
 		cin >> c1 >> n1 >> c2 >> n2;
 		bool flip = false;
 		if(1.0*c1/n1 > 1.0*c2/n2){
 			swap(c1,c2);
 			swap(n1,n2);
 			flip = true;
 		}
 		//a = n1, b = n2;
 		EEA(n1,n2);
 		if(n%d!=0){
 			cout << "failed" << endl;
 		}
 		else{
 			x = (n/d)*x;
 			y = (n/d)*y;
 			ll p1 = (ll)ceil( (double)(-x*d)/n2 );
 			ll p2 = (ll)floor( (double)(y*d)/n1 );
 			if(p1>p2){
 				cout << "failed" << endl;
 				continue;
 			}
 			x+=n2/d*p2;
 			y-=n1/d*p2;
 			if(flip){
 				swap(x,y);
 			}
 			cout << x <<' '<<y << endl;
 		}
 	}
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; //cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


