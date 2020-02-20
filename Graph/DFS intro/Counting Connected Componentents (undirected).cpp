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

vector<int>adj[maxn];
bool vis[maxn];
vector<int>CC[maxn];
int ConnectedComponents = 0;
void dfs(int v){
    vis[v] = 1;
    cout<<v<<" ";
    CC[ConnectedComponents].push_back(v);
    for(auto child: adj[v]){
        if(vis[child]==0){
            dfs(child);
        }
    }
}
int main(){
        _ios;

        fill(vis);

        int node,edge;
        cin>>node>>edge;

        for(int i = 1; i<=edge; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i<=node; i++){
            if(vis[i]==0){
                dfs(i);
                ++ConnectedComponents;
            }
        }
        cout<<endl<<"#Number Of CC "<<ConnectedComponents<<endl;
        for(int i = 0; i<ConnectedComponents;i++){
            for(auto x: CC[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        cout<<endl;



return 0;
}

/*
7 7
1 5
5 2
5 6
6 4
6 8
8 2
3 7


*/
