class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for(int num:nums)totalSum += num;
       
        int k = totalSum - x;
        
        int startPos = 0;
        int maxSubarrayLength = -1;
        int sum = 0;
        
        for(int endPos = 0; endPos < (int)nums.size(); endPos++){
            sum += nums[endPos];
            while(startPos <= endPos and sum > k){
                sum -= nums[startPos];
                startPos++;
            }
            if(sum == k){
                maxSubarrayLength = max(endPos - startPos + 1, maxSubarrayLength);
            }
        }
        return (maxSubarrayLength == -1 ? -1 : (int)nums.size() - maxSubarrayLength);
    }
};
