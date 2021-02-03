//https://codeforces.com/contest/630/problem/K

#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

ll one(ll n){
    ll cnt = 0;
    while(n){
        if(n%2)cnt++;
        n/=2;
    }
    return cnt;
}
bool ithBitSet(int mask, int pos){
    //suppose mask = 10101, we have to check 3rd bit set or not
    // then simply, 1<<3 = 100 = 8;
    // then do AND operation , we know 1&1 = 1 only, rest are 0
    return mask&(1<<pos);
}

void task(){
    ll n; cin >> n;
    std::vector<int>d = {2, 3, 5, 7};
    ll possible = n;

    ll Numerator = n, Denominator; // a/b, a = Nume, b = Deno
    
    for(ll mask = 1; mask<=(1<<d.size()) - 1; mask++){
        Denominator = 1ll;
        ll setbit = one(mask); // builtinpopcount
        for(int i = 0; i<d.size(); i++){
            if(ithBitSet(mask, i)){
                Denominator*=d[i];
            }
        }
        if(setbit&1)possible-=(Numerator/Denominator);
        else possible+=(Numerator/Denominator);
    }
    cout << possible << endl;
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
