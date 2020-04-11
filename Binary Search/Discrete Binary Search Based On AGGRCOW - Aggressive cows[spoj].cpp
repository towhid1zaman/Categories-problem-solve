
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 1000100;


bool chek(int minDis,int pos[],int n, int c){
        int cnt = 1;
        int last = pos[0];
        for(int i = 1; i<n; i++){
            if(pos[i]-last>=minDis){
                last = pos[i];
                ++cnt;
            }
            if(cnt==c){
                return true;
            }
        }
        return false;
}

int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            int n,c;

            cin >> n >> c;
            int pos[n+1];
            for(int i = 0; i<n; i++){
                cin >> pos[i];
            }
            sort(pos,pos+n);
            int l = 0;
            int h = pos[n-1]-pos[0]+1;
            while(h-l>0){
                int mid = (l+h+1)/2;
                if(chek(mid,pos,n,c)==true){
                    l = mid;
                }
                else h  = mid-1;
            }
            cout<<l<<endl;
        }


return 0;
}
/*
1
5 3
1
2
8
4
9

3
*/
