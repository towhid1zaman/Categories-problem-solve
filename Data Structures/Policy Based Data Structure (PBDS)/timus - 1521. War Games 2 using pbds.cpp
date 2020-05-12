
/*


এখানে বলেছে, n টা মানুষ একটা সার্কেলের মত করে দাঁড়িয়ে আছে। প্রথমবার k-th মানুষটা বেরিয়ে যাবে সার্কেল থেকে। এরপরেরবার হতে 
সার্কেলের সব মানুষ না চলে যাওয়া পর্যন্ত এর আগের স্টেপে যেই পজিশনের মানুষটা চলে গেছে, তার ঠিক পরের k-th মানুষটা এই স্টেপে বের হয়ে যাবে।

*/


// </> : towhid1zaman

#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) (v).erase(unique(all(v)),(v).end())
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int main(){
        _

        int n,k; cin >> n >> k;

        ordered_set s;
        for(int i = 1; i<=n; i++){
            s.insert(i);
        }
        int cur = 0;
        while(n){
            cur = (cur+k-1)%n;
            //cout<<cur<<endl;
            auto it = s.find_by_order(cur);
            cout<<*it<<endl;
            s.erase(it);
            n--;
        }

return 0;
}

