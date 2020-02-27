/*
        a and b deya ache, and they are both prime;
        i have to tell that how many  operation need to convert a to b;
        here operation is, every single step  , ami a'er jekono ekta digit change korte parbo
        and amon vabe change korbo jeno seta prime hoi.

        approach:
            SSSP using bfs;
            1000 theke 9999 porjonto jotogula prime ache, taderke niye graph build korbo
            sudhu matro je duita node er digit difference 1 hobe tara connected hobe

            and finally dist[b] is ans;

*/
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
int vis[maxn];
int dist[maxn];
vi primes;

bool isValid(int a,int b){
    int cnt = 0;
    while(a>0){
        if(a%10 != b%10)cnt++;
        a/=10;
        b/=10;
    }
    if(cnt==1)return true;
    else return false;
}
bool isPrime(int n){
    for(int i = 2; i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}
void buildgraph(){
    for(int i = 1000; i<=9999; i++){
        if(isPrime(i)){
            primes.pb(i);
        }
    }
    for(int i = 0; i<sz(primes);i++){
        for(int j = i+1; j<sz(primes);j++){
            int u = primes[i];
            int v = primes[j];
            if(isValid(u,v)){
                adj[u].pb(v);
                adj[v].pb(u);
            }
        }
    }
}

void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int child: adj[u]){
            if(vis[child]==0){
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[u]+1;
            }
        }
    }
}
int main(){
        _ios;

        buildgraph();
        int T; cin >> T;
        while(T--){
            int a,b; cin >> a >> b;
            for(int i = 1000; i<=9999;i++){
                dist[i] = -1;
                vis[i] = 0;
            }
            bfs(a);
            if(dist[b]==-1){
                cout<<"Impossible"<<endl;
            }
            else cout << dist[b] <<endl;
        }




return 0;
}





