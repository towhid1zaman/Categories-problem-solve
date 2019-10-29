///616D Longest k-Good Segment


#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair <int, int> pii;
typedef vector<pii>vip;
#define all(v) (v).begin(),(v).end()
#define sp(x,k) cout<<setprecision(k)<<fixed<<x<<endl;
#define rep(i,a,b) for(int i =(a); i <=(b); ++i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair
const int mod = 1000000007; // (int)1e9+7
const int N = 2000010;

vi v(N);
int L,R;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cerr.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i = 1; i<=n;i++){
        cin>>v[i];
    }
    set<int>s;
    multiset<int>ms;
    int cnt = 0;
    L = 1;
    R=n;
    int left,right;
    left = 1;
    for(int r = 1; r<=n;r++){
        s.insert(v[r]);
        ms.insert(v[r]);
        while(s.size()>k){
            ms.erase(ms.lower_bound(v[left]));
            if(ms.count(v[left])==0)
                s.erase(v[left]);
            left++;
        }
        //cout<<left<<endl;
        if(s.size()==k and r-left+1>cnt){
            L = left;
            R = r;
            cnt = r- left+1;
        }
    }
    cout<<L<<" "<<R<<endl;


return 0;
}

