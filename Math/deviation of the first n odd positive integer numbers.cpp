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

const int maxn = 200005;
const int mod = 1000000007;

long double first_sum_of_nSquare(long double n){
    return (n*(n+1)*(2*n+1))/6;
}
long double first_sum_of_n(long double n){
    return (n*(n+1))/2;
}
void task(){
    sp(6);

    long double n;
    while(cin >> n){
        if(!n)break;
        long double x = first_sum_of_nSquare(n*2);
        long double y = first_sum_of_nSquare(n)*4;
        long double op = x - y;
        long double z = first_sum_of_n(n*2) - (2 * first_sum_of_n(n));
        long double avrg = z/n;
        long double ans = (op - 2*avrg*z + avrg*avrg*n)/(n-1);
        cout << sqrt(ans) << endl;
    }
}
///UVA-13096
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1;// cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
