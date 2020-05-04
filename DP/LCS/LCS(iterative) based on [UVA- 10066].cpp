
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int LCS(vi a , vi b, int n1,int  n2){
    int L[n1+1][n2+1];
    for(int i = 0; i<=n1; i++){
        for(int j = 0; j<=n2; j++){
            if(i==0 or j==0)L[i][j]= 0 ;
            else if(a[i-1]==b[j-1]){
                L[i][j]  = 1+ L[i-1][j-1];
            }
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    return L[n1][n2];
}

int main(){
        _ios;

        int n1,n2;
        int cs = 1;
        while(cin >> n1 >> n2){
            if(n1==0 and n2==0)break;

            vi a(n1),b(n2);
            for(int i = 0; i<n1; i++){
                cin >> a[i];
            }
            for(int i = 0 ; i<n2; i++){
                cin >> b[i];
            }
            cout<<"Twin Towers #"<<cs++<<endl;
            cout<<"Number of Tiles : "<<LCS(a,b,n1,n2)<<endl<<endl;
        }

return 0;
}

/*
    Application Of LCS

*/

