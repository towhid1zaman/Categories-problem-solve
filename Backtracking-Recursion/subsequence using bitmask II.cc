#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;

std::vector<int>bn(int n){
    std::vector<int>binary;
    while(n){
        binary.push_back(n%2);
        n/=2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}
void print(std::vector<int> v){
    for(auto x: v){
        cout << x <<' ';
    }
    cout << endl;
}

bool ithBitSet(int mask, int pos){
    //suppose mask = 10101, we have to check 3rd bit set or not
    // then simply, 1<<3 = 100 = 8;
    // then do AND operation , we know 1&1 = 1 only, rest are 0
    return mask&(1<<pos);
}
void task(){
    int n; cin >> n;
    std::vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    // generate subsequence using bitmask
    // if n is size of array then , possible 2^n - 1 subsequence

    for(int mask = 0; mask<(1<<n); mask++){
        // instead of checking all binary digit we can check weather mask bit set or not
        std::vector<int>sub;       
        for(int i = 0; i<n; i++){
            if(ithBitSet(mask, i)){
                sub.push_back(a[i]);
            }
        }
        print(sub);
        sub.clear();
    }
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
