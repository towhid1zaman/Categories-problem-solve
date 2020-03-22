
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


int p[maxn];
int Size[maxn];

int Find(int x){
    if(p[x]==x)return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b){
    int x = Find(a);
    int y = Find(b);
    p[y] = x;

    if(Size[x]>=Size[b]){
        Size[x]+=Size[b];
    }
    else{
        Size[y]+=Size[x];
    }
}


int main(){
        _ios;
        int n, e; cin >> n >> e;
        for(int i = 1; i<=n; i++){
            p[i] = i;
            Size[i]=1;
        }
        for(int i = 1;i<=e; i++){
            int a, b; cin >> a >> b;
            Union(a,b);
        }
        set<int>tot;
        for(int i = 1; i<=n;i++){
            tot.insert(p[i]);
        }
        cout<<"Total Connected Components : "<<sz(tot)<<endl;
        cout<<"Where They Belongs, means his root :"<<endl;
        for(int i = 1; i<=n; i++){
            cout<<i<<" Belongs to "<<p[i]<<endl;
        }
        cout<<"Size of each Connected Components : "<<endl;
        for(auto x: tot){
            cout<<"Size of "<<x<<" is "<<Size[x]<<endl;
        }


return 0;
}

/*
6 4
1 2
2 3
3 4
5 6
*/




