
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair< int, int > pii;
typedef pair< pii, int > ppi;
#define fill(a,b) memset(a,b,sizeof(a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0;i<a;i++)
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
const int inf = 0x3f3f3f3f;
const int maxn = 2000100;


char s[maxn];

int main(){
        _
        string s;
        while(cin >> s){
            int i=0;
            list<char>l;
            list<char>::iterator it;
            it = l.end();
            while(s[i]){
                if(s[i]=='['){
                     it = l.begin();
                }
                else if(s[i]==']'){
                     it = l.end();
                }
                else{
                    l.insert(it,s[i]);
                }
                i++;
            }
            for(auto x: l){
                cout<<x;
            }cout<<endl;
        }

return 0;
}
/*
    list is STL container

    we can insert value , in begin or ending position of a list .

    here , at first we iterator int end position,
    we insert value to list ,
    like this. a.b.c.d.....

    we change iterator end to begin(),
    then we start insert from begin()
    like this..
    x.y.z... [prvious element]
    x.y.z... [a.b.c.d.....]

    then finally we print the ans

*/

