
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
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
const int inf = 0x3f3f3f3f;
const int maxn = 100005;

ll h[maxn];
void histogram(ll n){
    stack<ll>st;
    ll ans = 0;
    ll i;
    for(i = 0; i<n;){
        if(st.empty() or h[st.top()]<=h[i]){
            st.push(i);
            i++;
        }
        else{
            ll top = st.top();
            st.pop();
            ll width = 0;
            if(st.empty())width = i;
            else width = i - st.top() - 1;
            ll area = h[top] * width;
            ans = max(ans,area);
        }
    }

    while(!st.empty()){
            ll top = st.top();
            st.pop();
            ll width;
            if(st.empty())width = i;
            else width = i - st.top() - 1;
            ll area = h[top] *  width;
            ans = max(ans, area);
    }
    cout<<ans<<endl;
}

int main(){
        _

        int T; cin >> T;
        for(int cs = 1;cs<=T; cs++){
            ll n; cin >> n;
            for(ll i = 0; i<n; i++){
                cin >> h[i];
            }
            cout<<"Case "<<cs<<": ";
            histogram(n);
        }
return 0;
}


