#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a,b) for(int i =(a); i <=(b); ++i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define pb push_back

int dx4[ ] = {0,0,1,-1};
int dy4[ ] = {1,-1,0,0};
int dx8[ ] = {0,0,1,1,1,-1,-1,-1};
int dy8[ ] = {1,-1,1,-1,0,0,-1,1};

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 200100;

vector<int>adj[maxn];
int edge,node;

void bfs(int s)
{
    //used.clear(),d.clear().p.clear();
    queue<int>q;
    vector<int>used(node);
    vector<int>d(edge),p(edge);
    q.push(s);
    used[s]  = true;
    p[s] = -1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u: adj[v])
        {
            if(!used[u])
            {
                used[u] = true;
                q.push(u);
                d[u] = d[v]+1;
                p[u] = v;
            }
        }
    }

    for(int i = 1; i<=node;i++)
    {
        if(!used[i]){
            cout<<"No path "<<endl;
        }
        else{
            vector<int>path;
            for(int v = i; v!= -1; v = p[v]){
                path.push_back(v);
            }
            reverse(all(path));
            cout<<"Path : "<<s<<" to "<<i<<endl;
            cout<<"Total path "<<d[i]<<endl;
            for(auto v: path){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
}
int main(){

    IOS;
    cin>>edge>>node;
    for(int i = 1; i<=edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source;
    cin>>source;
    bfs(source);





return 0;
}





