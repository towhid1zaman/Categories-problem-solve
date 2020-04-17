
//complexity: O(n*m); n = s.size(),m = t.size();

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
#define ff first
#define ss second
#define pb push_back
#define sz(x) (int)x.size()

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2100;
string s,t;
int len1,len2;
int dp[maxn][maxn];
int LCS(int i,int j){
        if(i==s.size() or j==t.size())return 0;
        if(dp[i][j] !=-1)return dp[i][j];
        int ans = 0;
        if(s[i]==t[j])ans = 1+ LCS(i+1,j+1);
        else{
            int way1 = LCS(i+1,j);
            int way2 = LCS(i,j+1);
            ans = max(way1,way2);
        }
        dp[i][j] = ans;
        return dp[i][j];
}
string ans;
void printLCS(int i,int j){
    if(i==len1 or j==len2){
        return;
    }
    if(s[i]==t[j]){
        ans+=s[i];
        printLCS(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}
int main(){
        _ios;
        memset(dp,-1,sizeof dp);
        cin>>s>>t;
        len1 = s.length();
        len2 = t.length();
        int len = LCS(0,0);
        printLCS(0,0);
        cout<<len<<endl;
        cout<<ans<<endl;



return 0;
}




