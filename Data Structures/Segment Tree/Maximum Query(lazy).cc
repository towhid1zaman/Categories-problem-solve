//https://codeforces.com/contest/272/problem/C
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef vector<pii>vip;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int inf = 0x3f3f3f3f;// (int)3e18;
const int maxn = 100006;
const ll INF = 1e15;
ll a[maxn];
ll tree[4*maxn];
ll lazy[4*maxn];

void build(ll node, ll left, ll right)
{
    lazy[node] = 0;
    if (left==right)
    {
        tree[node] = a[left];
        return;
    }
    ll mid = (left+right)/2;
    build(2*node, left, mid);
    build(2*node+1, mid+1, right);
    ll l = tree[2*node], r = tree[2*node+1];
    tree[node] = max(l,r);
}
void updateChild(ll node, ll left, ll right)
{
    tree[node] = lazy[node];
    if (left < right)
    {
        lazy[2*node] = lazy[node];
        lazy[2*node+1] = lazy[node];
    }
    lazy[node] = 0;
}
void update(ll node, ll left, ll right, ll start, ll end, ll val)
{
    if (lazy[node]) updateChild(node, left, right);
    if (start <= left && right <= end)
    {
        lazy[node] = val;
        return;
    }
    if (right < start || end < left) return;
    ll mid = (left+right)/2;
    update(2*node, left, mid, start, end, val);
    update(2*node+1, mid+1, right, start, end, val);
    ll l = lazy[2*node] ? lazy[2*node]:tree[2*node], r = lazy[2*node+1] ? lazy[2*node+1]:tree[2*node+1];
    tree[node] = max(l,r);
}
ll query(ll node, ll left, ll right, ll start, ll end)
{
    if (lazy[node]) updateChild(node, left, right);
    if (start <= left && right <= end) return tree[node];
    if (right < start || end < left) return 0;
    ll mid = (left+right)/2;
    ll l = query(2*node, left, mid, start, end);
    ll r = query(2*node+1, mid+1, right, start, end);
    return max(l,r);
}

void task(){
    ll n; cin >>n;
    for(ll i = 1; i<=n; i++){
        cin >> a[i];
    }
    build(1,1,n);
    ll q; cin >> q;
    while(q--){
        ll w,h; cin >> w >> h;
        ll ans = query(1,1,n,1,w);
        cout << ans << endl;
        update(1,1,n,1,w,ans+h);
    }
}

int main(){
        _
        int T = 1; //cin >> T;
        while(T--){
            task();
        }
return 0;
}
