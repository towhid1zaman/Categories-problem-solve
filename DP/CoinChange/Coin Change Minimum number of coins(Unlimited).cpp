class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1, 10004);
        dp[0] = 0;
        for(int i = 1; i<=amount; i++){
            for(int j = 0; j<(int)coins.size(); j++){
                if(coins[j] > i)continue;
                dp[i] = min(dp[i], 1+dp[i-coins[j]]);
            }
        }
        if(dp[amount] == 10004)return -1;
        else return dp[amount];
    }
};
