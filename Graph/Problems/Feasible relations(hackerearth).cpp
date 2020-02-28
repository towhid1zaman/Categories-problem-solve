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
const int maxn = 2000100;

vi adj[maxn];
int vis[maxn], cc[maxn];
int cur_cc;

void dfs(int node){
    vis[node] = 1;
    cc[node] = cur_cc;
    for(int child: adj[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }
}
int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            int n,k;
            cin >> n>> k;
            for(int i = 1; i<=n;i++){
                adj[i].clear();
                vis[i] = 0;
            }
            int u,v;
            string s;
            vector<pair<int,int>> edgelist;
            for(int i = 1; i<=k;i++){
                cin>>u>>s>>v;
                if(s=="="){
                    adj[u].pb(v), adj[v].pb(u);
                }
                else
                    edgelist.pb({u,v});
            }

            for(int i = 1; i<=n; i++){

                if(vis[i]==0)
                    cur_cc++;
                    dfs(i);
            }

            bool flag = true;

            for(int i = 0; i<sz(edgelist); i++){
                int a = edgelist[i].ff;
                int b = edgelist[i].ss;
                if(cc[a]==cc[b]) flag = false;
            }
            if(flag){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;
        }



return 0;
}





