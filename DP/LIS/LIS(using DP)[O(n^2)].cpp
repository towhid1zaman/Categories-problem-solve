
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const int maxn = 200100;

int dp[maxn];
int LIS(vector<int>v, int n){
        int ans = 0;
        for (int i = 0; i < n; i++) {
        dp[i] = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
        _ios;

        int n; cin >> n;
        vector<int>v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }

        int ans = LIS(v,n);
        cout<<ans<<endl;

return 0;
}

/*

10
4 5 6 1 2 3 4 7 5 10

6

*/

