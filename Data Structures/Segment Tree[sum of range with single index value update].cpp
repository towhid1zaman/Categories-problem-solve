

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

int arr[maxn];
int tree[maxn];

void Build(int node, int b, int e){
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e) / 2;
    Build(left,b,mid);
    Build(right,mid+1,e);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int b,int e, int i, int j){
    if(i>e or j<b){
        return 0; //out of range
    }
    if(b>=i and e<=j){
        return tree[node];
    }
    int left = node*2;
    int right = node * 2 + 1;
    int  mid = (b+e)/2;
    int p1 = query(left, b,mid,i,j);
    int p2 = query(right, mid+1,e,i,j);
    return p1+p2; // sum of left and right
}

void update(int node,int b, int e, int i, int newvalue){
    if(i>e or i<b){
        return; // out of range
    }
    if(b >= i and e <= i){
        tree[node]  = newvalue; //assign new value
        return;
    }
    int left = node*2;
    int right = node*2 + 1;
    int mid = (b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right, mid+1,e,i,newvalue);
    tree[node] = tree[left] + tree[right];
}
int main(){
        _ios;

        int n;
        cin>>n;
        for(int i = 1; i<=n;i++){
            cin>>arr[i];
        }
        Build(1,1,n);
        update(1,1,n,2,0);
        cout<<query(1,1,n,1,3)<<endl;
        update(1,1,n,2,2);
        cout<<query(1,1,n,2,2)<<endl;

        return 0;



return 0;
}
/*

7
4 -9 3 7 1 0 2

*/




