//https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxAns = 0, startPos = 0, sum = 0;
        bool mark[11111]={false};
        for(int endPos = 0; endPos < (int)nums.size(); endPos++){
            while(mark[ nums[endPos] ]){
                sum -= nums[startPos];
                mark[ nums[startPos] ] = false;
                startPos++;
            }
            
            sum += nums[endPos];
            maxAns = max(maxAns, sum);
            mark[ nums[endPos] ] = true;
            
        }
        
        return maxAns;
    }
};
