
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
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
const int maxn = 2000100;

int main(){
        _
	int DP[5842] = {1}, t2 = 0, t3 = 0, t5 = 0, t7 = 0;
	int tmp, i;
	for(i = 1; i < 5842; i++) {
		while(DP[t2]*2 <= DP[i-1])	t2++;
		while(DP[t3]*3 <= DP[i-1])	t3++;
		while(DP[t5]*5 <= DP[i-1])	t5++;
		while(DP[t7]*7 <= DP[i-1])	t7++;
		tmp = DP[t2]*2;
		if(DP[t3]*3 < tmp)	tmp = DP[t3]*3;
		if(DP[t5]*5 < tmp)	tmp = DP[t5]*5;
		if(DP[t7]*7 < tmp)	tmp = DP[t7]*7;
		DP[i] = tmp;
	}
	int n;
	while(scanf("%d", &n) == 1 && n) {
		printf("The nth number  %d.\n", DP[n-1]);
	}
return 0;
}
