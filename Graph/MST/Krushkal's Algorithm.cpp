
// </> : towhid1zaman

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
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const int INF = 1e9 + 10;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

/*
    This is Krushkal's Algorithm , Here first of all
    we have to sort our edges by their weight
    in increasing order.

    then just check they have same parent or not,
    then simply merge them
    and finally sum the weight

*/

struct edges{
    int a;
    int b;
    int w;
};

edges adj[maxn];
int p[maxn];

bool comp(edges a, edges b){
    if(a.w<b.w){
        return true;
    }
    return false;
}

int Find(int x){
    if(p[x]==x)return x;
    return p[x] = Find(p[x]);
}

void Union(int a, int b){
    p[Find(b)] = Find(a);
}

int main(){
        _ios;

        int n,m,a,b,w;
        cin >> n >> m;
        for(int i = 1; i<=n; i++){
            p[i] = i;
        }
        for(int i = 0; i < m; i++){
            cin >> adj[i].a >> adj[i].b >> adj[i].w;
        }
        int sum = 0;

        sort(adj,adj+m,comp);

        for(int i = 0; i<m; i++){
            a = Find(adj[i].a);
            b = Find(adj[i].b);
            if(a!=b){
                    Union(a,b);
                    sum+=adj[i].w;
            }
        }
        cout<<sum<<endl;

return 0;
}


/*

4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
ans=19;

6 9
1 2 9
1 6 6
2 4 2
2 3 14
3 4 9
3 5 1
4 5 10
4 6 11
5 6 15
ans = 27;
*/



