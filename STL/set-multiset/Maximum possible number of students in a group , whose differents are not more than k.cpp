///1133C Balanced Team
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector<pii>vip;
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a,b) for(int i =(a); i <=(b); ++i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
const int mod = 1000000007; // (int)1e9+7
const int N = 200100;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    int n;
    cin>>n;
    vll v(n);
    map<int,int>cnt;
    set<int>s;
    for(int i = 0; i<n;i++){
        cin>>v[i];
        cnt[v[i]]++;
        s.insert(v[i]);
    }
    int ans = 0;
    for(auto a: s){
        int res = cnt[a];
        for(int i = 1; i<=5;i++){
            res+=cnt[a+i];
        }
        ans = max(ans,res);
    }
    cout<<ans<<endl;







return 0;
}




