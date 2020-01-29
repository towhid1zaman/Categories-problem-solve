#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define getpos(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define sz(x) (int)x.size()

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;
int arr[maxn];
int ternarySearch(int left,int right, int number){
    if(right-left>0){
        int midfirst = left + (right-left)/3;
        int midsecond = midfirst + (right - left)/3;
        if(arr[midfirst]==number){
            return midfirst;
        }
        if(arr[midsecond]==number){
            return midsecond;
        }
        if(number<arr[midfirst]){
            return ternarySearch(left,midfirst,number);
        }
        if(number>arr[midsecond]){
            return ternarySearch(midsecond,right,number);
        }
        return ternarySearch(midfirst,midsecond,number);
    }
    else{
        return -1;
    }
}
int main(){
        _ios;

        int n;
        cin>>n;
        for(int i = 0; i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int number;
        cin>>number;
        cout<<"position of given number "<<ternarySearch(0,n-1,number)<<endl;




return 0;
}
/*
10
5 10 14 15 20 30 25  32 35 38
25

*/




