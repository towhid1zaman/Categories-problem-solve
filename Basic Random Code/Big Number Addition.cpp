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
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const int INF = 1e9 + 10;
const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 20000;

string add(char a[], char b[])
{
    int i, j, carry, k, t1, t2;
    char res[1010];
    int len1 = strlen(a);
    int len2 = strlen(b);

    carry = k = 0;

    for(i = len1 - 1, j = len2-1; i >= 0 || j >= 0; i--, j--)
    {
        t1 = t2 = 0;
        if(i >= 0) t1 = a[i] - '0';
        if(j >= 0) t2 = b[j] - '0';

        res[k++] = ((t1 + t2 + carry)%10) + '0';
        carry = (t1 + t2 + carry) / 10;
    }

    while(carry != 0)
    {
        res[k++] = (carry % 10) + '0';
        carry /= 10;
    }
    res[k] = '\0';
    reverse(&res[0], &res[k]);
    return res;
}

int main(){
        _ios;
        char a[1000], b[1000];
        string res;
        while(scanf("%s %s", a, b)==2){
        res = add(a, b);
        cout<<res<<endl;
        }





return 0;
}





