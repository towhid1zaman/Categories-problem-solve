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
const int maxn = 2000100;
int coin[] = {1,5,10,25,50};
int make;
int dp[10][maxn];
int solve(int i,int tk){
    if(i>=5){
        if(tk==0){
            return 1;
        }
        else return 0;
    }
    if(dp[i][tk] !=-1) return dp[i][tk];
    int way1 = 0, way2 = 0;
    if(tk - coin[i]>= 0) way1 = solve(i,tk - coin[i]); ///take i
    way2 = solve(i+1,tk); // don't take

    return dp[i][tk] = way1+way2; /// total possible way

}

int main(){
        _ios;
        int n;
        memset(dp,-1,sizeof dp);
        while(cin>>n){
            cout<<solve(0,n)<<endl;
        }




return 0;
}





