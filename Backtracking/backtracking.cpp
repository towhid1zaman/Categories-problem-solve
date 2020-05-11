
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

int n;
vector<int>subset;
void subset_search(int k){
    if(k==n+1){
        //generating subset
        for(auto x:subset){
            cout<<x<<' ';
        }cout<<endl;
    }
    else{
        //include k in the subset
        subset.push_back(k);
        subset_search(k+1);
        subset.pop_back();
        //don't include k in the subset
        subset_search(k+1);
    }
}

void GeneratingSubset(){
    cin >> n;
    //total subset will be 2^n
    subset_search(1);
}

int p;
vector<int>permutation;
bool chosen[100+1];
void permutation_search(){
    if(permutation.size()==p){
        for(int x:permutation)cout<<x<<' ';cout<<endl;
    }
    else{
        for(int i = 1; i<=p; i++){
            if(chosen[i])continue;
            chosen[i] = true;
            permutation.push_back(i);
            permutation_search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}
void GeneratingPermutation(){
    cin >> p;
    permutation_search();

    ///int stl c++ we have a buitin fucnction called nextpermutaion we can also generate permutation using this
    /*
    for(int i = 1; i<=p; i++){
        permutation.push_back(i);
    }
    int cnt = 0;
    do{
        for(auto x:permutation)cout<<x<<' ';cout<<endl;
        cnt++;
    }while(next_permutation(permutation.begin(),permutation.end()));

    //p! = p*(p-1)*(p-2)...
    cout<<cnt<<endl;
    */
}

int main(){
        _
        //GeneratingSubset();
        //GeneratingPermutation();

return 0;
}
