///Codeforces Testing Round #1, problem: (C) Circular RMQ
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
const int maxn = 200010;
const ll INF = 1e15;
ll a[maxn];
ll tree[4*maxn];
ll lazy[4*maxn];

void build(int node, int b, int e){
    if(b>e)return;
    if(b==e){
        tree[node] =  a[b];
        return;
    }
    int left = node*2;
    int right =node*2 +1 ;
    int mid = (b+e)/2;
    build(left, b, mid);
    build(right, mid+1,e);
    tree[node] = min(tree[left], tree[right]);
}

void update(int node,int b, int e,int i, int j, int newvalue){
    int left = node*2;
    int right  = node*2 +1;
    int mid = (b+e)/2;
    if(lazy[node] !=0){//this node need tobe updated
        tree[node] += lazy[node]; //update it
        if(b!=e){
            lazy[left] += lazy[node]; //Mark child as lazy;
            lazy[right]+=lazy[node]; // Mark child as lazy;
        }
        lazy[node] = 0; /// Reset it;
    }

    if(b>e or b>j or e<i){///Current Segment is not within range [i,j]
        return;
    }
    if(b>=i and e<=j){///Segment is fully within range
        tree[node] += newvalue;
        if(b != e){///Not Leaf Node
            lazy[left] +=newvalue;
            lazy[right] +=newvalue;
        }
        return;
    }
    //updating left and right child
    update(left, b, mid, i, j,newvalue);
    update(right,mid+1,e, i, j,newvalue);

    tree[node] = min(tree[left], tree[right]); // Updating root with min value
}

ll query(int node, int b, int e, int i, int j){
        int left = node*2;
        int right = node*2 +1;
        int mid = (b+e)/2;
        //if(b>e or b>j or e<i) return INF; /// out of range
        if(lazy[node] !=0){//This node needs to be updated
            tree[node] += lazy[node]; //Update it
            if(b!=e){
                lazy[left] += lazy[node];
                lazy[right] += lazy[node];
            }
            lazy[node] = 0;
        }
        if(b>e or b>j or e<i) return INF;
        if(b>=i and e<=j ) return tree[node];
        ll p1 =  query(left, b,mid, i, j);
        ll p2 =  query(right,mid+1,e, i, j);
        return min(p1,p2);
}
int main(){
        _ios;


        int n;
        cin>>n;
        for(int i =1; i<=n;i++){
            cin>>a[i];
        }
        build(1,1,n);

        int Q;
        cin>>Q;
        while(Q--){
            int l,r;
            cin>>l>>r;
            ++l,++r;
            char ch;
            cin.get(ch);
            if(ch==' '){
                int v;cin>>v;
                if(l>r){
                        //swap(l,r);
                        update(1,1,n,l,n,v);
                        update(1,1,n,1,r,v);
                }
                else update(1,1,n,l,r,v);
            }
            else{
                if(l>r){
                    ll q1 = query(1,1,n,l,n);
                    ll q2 = query(1,1,n,1,r);
                    cout<<min(q1,q2)<<endl;
                }
                else cout<<query(1,1,n,l,r)<<endl;
            }
        }





return 0;
}





