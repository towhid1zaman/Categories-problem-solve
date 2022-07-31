//https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = (int)nums.size() + 1;
        int sum = 0;
        int startPos = 0;
        for(int endPos = 0; endPos<(int)nums.size(); endPos++){
            sum += nums[endPos];
            while(sum >= target){
                ans = min(ans, endPos - startPos + 1);
                sum -= nums[startPos];
                startPos++;
            }
        }
        
        return ans == (int)nums.size() + 1 ? 0:ans;
    }
};
