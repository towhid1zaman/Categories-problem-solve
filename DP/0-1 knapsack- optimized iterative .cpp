///https://www.spoj.com/problems/PARTY/

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
int KnapSack(int val[], int wt[], int n, int W)
{
	int dp[W+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i < n; i++)
		for(int j=W; j>=wt[i]; j--)
			dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
	return dp[W];
}
int main(){
        _ios;
        int w,n;
        cin>>w>>n;
        int val[n+1],wt[n+1];
        for(int i = 0; i<n;i++){
            cin>>val[i]>>wt[i];
        }
        cout<<KnapSack(val,wt,n,w)<<endl;


return 0;
}



