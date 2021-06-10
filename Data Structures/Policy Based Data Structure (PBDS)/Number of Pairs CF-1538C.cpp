//https://codeforces.com/contest/1538/problem/C

/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less_equal<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<type>os
// os.order_of_key(k) the number of elements in the os less than k
// *os.find_by_order(k) print the k-th smallest number in os(0-based)

const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;

void task(){
    int n; cin >> n;
    ll l,r; cin >> l >> r;
    std::vector<ll>a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    ordered_set<ll>os;
    ll ans = 0;

    sort(all(a));
    for(int i = 0; i<n;i++){
        ans += os.order_of_key(r - a[i] + 1) - os.order_of_key(l-a[i]);
        os.insert(a[i]);
    }
    cout << ans << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
