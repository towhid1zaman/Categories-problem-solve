
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
int dp[102][1002];
int n,w;
int wt[maxn], val[maxn];
void task(){
    fill(dp,0);
    cin >> n >> w;
    for(int i = 0; i<n; i++)cin>> wt[i];
    for(int i = 0; i<n; i++) cin >> val[i];

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max( val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else if(wt[i]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl;
}

int main(){
        _
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


/*
1
5 7
2 3 4 5 7
10 20 30 50 10
*/
