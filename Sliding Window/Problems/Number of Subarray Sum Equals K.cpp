class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
                
        int ans = 0;
        unordered_map<int, int>seen;
        seen[0] = 1;
        int curSum = 0;
        for(int endPos = 0; endPos < (int)nums.size(); endPos++){
            curSum += nums[ endPos ];
            ans += seen[ curSum - k ]; // k = cursum - previous sum
            seen[curSum]++;
        }
        
        return ans;
    }
};
