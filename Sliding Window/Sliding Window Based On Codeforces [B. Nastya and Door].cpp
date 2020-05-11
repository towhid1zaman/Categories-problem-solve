
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
        int T; cin >> T;
        while(T--){

                int n,k; cin >>  n >> k;
                vi a(n);
                rep(i,n) cin >> a[i];

                vector<bool>peak(n,0);
                for(int i = 1; i<n-1; i++){
                    /// a[i] peak or not
                    if(a[i]>a[i-1] and a[i]> a[i+1]){
                        peak[i] = 1;
                    }
                }
                int max_len = 0;
                // because first and last element isn't peak
                for(int i = 1; i<k-1; i++){
                    if(peak[i])max_len++;
                }
                int temp_len = max_len;
                int left = 1, right = k-1;
                int left_position = 1;
                for(int i = 1; i<n-k+1; i++){
                    if(peak[left])temp_len--;
                    if(peak[right])temp_len++;

                    left++, right++;
                    //updating max segment
                    if(temp_len>max_len){
                        left_position = i+1; // ans should be 1 indexed
                        max_len = temp_len;
                    }

                }

                cout<<max_len+1 <<' '<<left_position<<endl;

        }



return 0;
}

