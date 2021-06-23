/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
#define endl "\n"
#define pb push_back
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define all(v) (v).begin(),(v).end()

const double pi = acos(-1.0);
const int maxn = 2000006;
const int mod = 1000000007;
namespace String_Matching{
    std::vector<int> z_function(string s){
        int n = (int) s.length();
        std::vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i){
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
}using namespace String_Matching;


/*
 *int this problem you are given a string,
 *you have to find such maximum length substring that is prefix and suffix
 *of given string, at the same time tahat would be infix of given string.
 *Infix is substring somewhere between prefix and suffix.
*/

void task(){
    string s; cin >> s;
    int n = (int)s.length();
    std::vector<int> z = z_function(s);
    output_vector(z);
    int mx = 0, mx_p = 0;
    for(int i = 1; i<n; i++){
        if(z[i]+i == n and mx_p >= z[i]){
            mx = max(mx, z[i]);
        }
        mx_p = max(mx_p, z[i]);
    }
    if(!mx)cout << "Just a legend" << endl;
    else cout << s.substr(0, mx) << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
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
