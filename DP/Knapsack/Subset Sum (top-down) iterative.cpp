
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
/*

problem statement: given an array and sum, i have to tell in given array
is there present any subset that their total is given sum.

print yes or no

*/



bool dp[100][100];
bool SubSetSUm(int n, int sum){
    vi a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i =0; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            if(i==0)dp[i][j] = false;
            if(j==0)dp[i][j]=true;
        }
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=sum; j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j-a[i-1]] | dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

void task(){
    int n,sum; cin >> n >> sum;
    if(SubSetSUm(n,sum))cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
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

/*
5 11
13 21 2 8 9
YES
*/
