
/*
Given a string S (with length N) and a pattern P (with length M), find all the occurrence of P in S
Naive Approach: O(NM)
KMP Time complexity: O(N + M)
*/
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int phi[maxn];
void prefix_function(string s){
    int n = s.size();
    int index = 0;
    phi[0]=0;
    for(int i = 1; i<n; i++){
        while(index>0 and s[index] !=s[i]){
            index = phi[index-1];
        }
        if(s[i] == s[index]){
            index++;
        }
        phi[i] = index;
    }
}

void kmp_search(string s, string t) {
        int n = sz(s);
        int m = sz(t);
    	for(int i=0,j=0; i<n; i++) {
		while(j && s[i]!=t[j])
			j = phi[j-1];
		if(s[i]==t[j]) j++;
		if(j==m) {
			cout<<"occurence at "<< i-m+1<<endl;
			j = phi[j-1];
		}
	}
}

int main(){
        _ios;
        string s,p; cin >> s >> p;
        prefix_function(p);
        kmp_search(s,p);


return 0;
}


