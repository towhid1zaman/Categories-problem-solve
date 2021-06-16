//https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& a, int k) {
        int n = (int)a.size();        
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += a[i];
        }
        if(sum%k != 0)return false;

        long long part = sum/k;
        std::vector<long long>dp((1<<n),-1);

        dp[0] = 0;
        for(int mask = 0; mask < (1<<n); mask++){
            if(dp[mask] == -1)continue;

            for(int i = 0; i<n; i++){
                if( !(mask & (1 << i)) and dp[mask] + a[i] <= part){
                    dp[ mask | (1<<i) ] = (dp[mask]+a[i]) % part;
                }
            }
        }

        if(dp[ (1 << n) - 1] == 0){
            return true;
        }
        else return false;
    }
};
