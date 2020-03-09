
///1167/problems/C. News Distribution
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

int p[maxn];
int res[maxn];
int Find(int x){
    if(p[x]==x)return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b){
    p[Find(a)] = Find(b);
}
int main(){
        _ios;

        //DSU practice

        int n,m;
        cin>>n>>m;
        for(int i = 1; i<=n;i++){
            p[i] = i;
        }
        for(int i = 1; i<=m;i++){
            int k,x = -1,y;
            cin>>k;
            while(k--){
                    cin>>y;
                    if(x==-1){
                        x = y;
                    }
                    Union(x,y);
            }
        }

        for(int i = 1; i<=n;i++){
            res[Find(i)]++;
        }
        for(int i = 1; i<=n;i++){
            cout<<res[Find(i)]<<" ";
        }
        cout<<endl;

return 0;
}
