

// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

#define pii pair<int,int>
#define MX 1111
#define Clear(x) for(int i=0 ; i<=MX ; i++) x[i].clear() ;
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(x) ((int)(x).size())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define deb(x) cout<<#x <<"="<<x<<endl;
#define present(v,x) ((v).find(x)!=(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sp(k) cout<<setprecision(k)<<fixed;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()

#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)

#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define yn(k) if(k)puts("YES");else puts("NO");

vector<int> adj[MX];
vector<int> tin, low;
vector<bool> visited;
vector<int> cycles[MX];
vector<pii> ans;
int color[MX], par[MX], mark[MX];
int timer;

void dfs(int v, int p = -1) //Ariticulation Bridge
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                ans.push_back({v, to});
        }
    }
}

void find_bridges() //Bridge finding
{
    timer = 0;
    visited.assign(30, false);
    tin.assign(30, -1);
    low.assign(30, -1);
    for (int i = 0; i < 26; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

void DFSCycle(int u, int p,  int color[], int mark[], int par[], int &cnt) //Cycle Finding
{
    if (color[u] == 2)
    {
        return;
    }
    if (color[u] == 1)
    {
        cnt++;
        int cur = p;
        mark[cur] = cnt;
        while (cur != u)
        {
            cur = par[cur];
            mark[cur] = cnt;
        }

        for (int i = 1; i <= 26; i++)
        {
            if (mark[i] > 0)
            {
                cycles[mark[i]].push_back(i);
                mark[i] = -1;
            }
        }
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : adj[u])
    {
        if (v == par[u])
        {
            continue;
        }
        DFSCycle(v, u, color, mark, par, cnt);
    }
    color[u] = 2;
}


bool cmp(pii &a, pii &b)
{
    if(a.first > a.second)
        swap(a.first, a.second);

    if(b.first > b.second)
        swap(b.first, b.second);

    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

void subgraph(){
        int n; //Numbers of Edges
        cin>>n;

        for(int i=0; i<n; i++)
        {
            char a, b; //Connected Node
            cin>>a>>b; 

            int x = a-96, y = b-96; // char to int
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int cnt = 0;
        find_bridges();
        DFSCycle(1, 0, color, mark, par, cnt);

        cout<<"Number of subgraphs : "<< cnt+ans.size() <<endl;

        for (int i = 1; i <= cnt; i++) //Cycle printing
        {
            cout << "Subgraph " << i << ": ";
            for (int x : cycles[i])
            {
                char ch = int(x+96); //int to char
                cout << ch << " ";
            }
            cout << endl;
        }

        sort(ans.begin(),ans.end(), cmp); 
        for(int i=0; i<ans.size(); i++) //Others subgraphs printing
        {
            int u = ans[i].first, v = ans[i].second;
            char cu = int(u+96), cv = int(v+96); //int to char
            cout << "Subgraph " << ++cnt << ": " << cu << " " << cv << endl;
        }

}
int main(){
        _
#ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        
        int T = 1; //cin >> T;
        for(int __ = 1; __ <= T; __++){
            //cout <<"Case "<<__<<": ";
            subgraph();
        }
/*array size ?
 *n==1 ?
 *different approach ?
*/        
return 0;
}


/*
input:
11
a b
a i
a d
b c
c d
a x
x j
a e
e h
e f
f g

output:
Number of subgraphs : 8
Subgraph 1: a b c d 
Subgraph 2: a e
Subgraph 3: a i
Subgraph 4: a x
Subgraph 5: e f
Subgraph 6: e h
Subgraph 7: f g
Subgraph 8: j x
*/




