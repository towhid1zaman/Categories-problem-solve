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

void task(){
    int n; cin >> n;
    std::vector<int>a(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    // generate subsequence using bitmask
    // if n is size of array then , possible 2^n - 1

    for(int mask = 1; mask<(1<<n); mask++){

        std::vector<int>binary = bn(mask);
        //print(binary);        
        /*
        going right to left , means least bit to higher bit
        and check whether it set(1) or not(0), if(set then print cur element)
        */

        std::vector<int>sub;
        for(int i = 0; i<binary.size(); i++){
            int indx = binary.size() - i - 1;
            if(binary[indx]){
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
