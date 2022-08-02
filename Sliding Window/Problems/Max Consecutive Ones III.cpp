//https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int startPos = 0, endPos;
        for(endPos = 0; endPos < (int)nums.size(); endPos++){
            if(nums[endPos] == 0)k--;
            if(k < 0 and nums[startPos++] == 0){
                k++;
            }
        }
        return endPos - startPos;
    }
};
