/// spoj-KNAPSACK - The Knapsack Problem
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
const int maxn = 2010;
int dp[maxn][maxn];
int weight[maxn],cost[maxn];
int s,n;

int solve(int i,int w){
    if(i==n+1)return 0;
    if(dp[i][w] !=-1)return dp[i][w];
    int profit1 = 0, profit2 =0;
    if(w+weight[i]<=s)
        profit1 = cost[i] + solve(i+1, w+weight[i]);
    profit2 = solve(i+1,w);
    dp[i][w] = max(profit1,profit2);

    return  dp[i][w];
}
int main(){
        _ios;
        memset(dp,-1,sizeof dp);
        cin>>s>>n;
        for(int i= 1; i<=n;i++){
            cin>>weight[i]>>cost[i];
        }

        int res = solve(1,0);
        cout<<res<<endl;


return 0;
}




