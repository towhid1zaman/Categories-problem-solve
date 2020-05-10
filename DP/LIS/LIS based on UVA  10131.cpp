/*
  basically youre given pair of two array , w,s;
  you have to findout LIS such that w[0]<w[1]<w[2]..... and s[0]>s[1]>s[2]...

*/

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
const int maxn = 10010;

vector<pair<pair<int,int>,int>>v;
bool comp(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){
    return a.first.second>b.first.second;
}

void print_path(int *path,int end){
    if(end > -1){
        print_path(path,path[end]);
        cout<<v[end].second+1<<endl;
    }
}
int main(){
        _
        int a,b;
        int n = 0;
        while(cin >> a >> b){
               v.push_back({{a,b},n});
               n++;
        }
        sort(all(v),comp);
        /// longest increasing subsequence
        int L[1100];
        int path[1100];
        int gmax = 1;
        int end_pos = 0;
        L[0]=1; path[0]=-1;
        for(int i = 1; i<v.size(); i++){
            int lprev = -1;
            L[i] = 1;
            for(int j = 0; j<i; j++){
                if(v[j].first.first < v[i].first.first && v[j].first.second > v[i].first.second && L[i] < L[j] + 1) {
                    L[i] = L[j] + 1;
                    lprev = j;
                }
            }
            path[i] = lprev;
            if(gmax<L[i]){
                gmax = L[i];
                end_pos = i;
            }
        }

        cout<<gmax<<endl;
        print_path(path,end_pos);


return 0;
}
