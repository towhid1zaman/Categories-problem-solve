//https://www.spoj.com/problems/BUGLIFE/
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
const int maxn = 200000;
vi adj[maxn];
bool vis[maxn];
bool col[maxn];
bool dfs(int v, int c){
    vis[v] = 1;
    col[v] = c;
    for(auto child: adj[v]){
        if(vis[child]==0){
            if(dfs(child, c^1)==false) // passing opposite color using xor
                return false;
        }
        else
            if(col[child]==col[v])
                return false;
    }
    return true;
}

int main(){
        _ios;

        int T; cin >> T;
        for(int k = 1; k<=T;k++){
            int node, edge; cin >> node >> edge;
                for(int i = 1; i<=node;i++){
                    adj[i].clear();
                    vis[i] = 0;
                }
                for(int i = 1; i<=edge;i++){
                    int u,v; cin >> u >> v;
                    adj[u].push_back(v),adj[v].push_back(u);
                }

                bool f =  true;
                for(int i = 1; i<=node; i++){
                    if(vis[i]==0){
                        bool ans = dfs(i,0);
                        if(ans==false){
                            f = false;
                        }
                    }
                }
                cout<<"Scenario #"<<k<<":"<<endl;
                if(f){
                    cout<<"No suspicious bugs found!"<<endl;
                }
                else
                     cout<<"Suspicious bugs found!"<<endl;
        }




return 0;
}
/*
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4
*/



