
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
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
        int n; cin >>n;
        int k; cin >> k;
        vi a(n);

        rep(i,n)cin >> a[i];

        // sliding window
        int max_sum = 0;
        for(int i = 0; i<k; i++){
            max_sum+=a[i];
        }
        int t_sum = max_sum;
        int left = 0, right = k;
        for(int i = 1; i<n-k+1; i++){
            t_sum -= a[left];
            t_sum += a[right];
            left++, right++;
            max_sum = max(max_sum,t_sum);
        }
        cout<<max_sum<<endl;





return 0;
}

/*

    ekta array deya thakbe n size er
    amake bolte hobe k segment er sum koto, jeta kina maximum hote hobe

    suppose
    2 5 81 7 , and k = 3
    amra jodi ekhn 3 segemnt gula alada kori tahole dekha jabe,
    2 5 8 = sum, 15
    5 8 1 = sum, 14
    8 1 7 = sum, 16

    so amader ans hobe 16,
    amra jodi barbar loop chaliye korte jai tahole etar complexity o(n^2) hobe

    but eta amra o(n) e korte pari sliding window technique er maddhome

    initially amra k segment er sum rekhe dichi, then two pointer left and right rakhchi
    left = 0, and right = k
    for 1 to n-k+1 porjonto loop chaliye babar
        picher elemnt ke remove kore samnr element add korchi and max value update korchi

