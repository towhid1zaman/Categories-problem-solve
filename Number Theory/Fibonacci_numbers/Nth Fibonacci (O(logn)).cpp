#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

std::map<ll,ll> Fib;
ll nthFib(ll n){
    if(n==0)return 0;
    if(n==2 or n==1)return 1;
    if(Fib.count(n)) return Fib[n];
    if(n%2==0){
        ll k = n/2;
        ll a = nthFib(k-1), b = nthFib(k);
        return Fib[n] = ((((2ll *a )% mod + b)%mod* b)%mod)%mod;
    }
    else{
        ll k = (n+1)/2;
        ll a = nthFib(k-1), b = nthFib(k);
        return Fib[n] = ((a * a)%mod + (b * b)%mod)%mod; 
    }
}
void task(){
    ll n;
    cin >> n;
    cout << nthFib(n) << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
