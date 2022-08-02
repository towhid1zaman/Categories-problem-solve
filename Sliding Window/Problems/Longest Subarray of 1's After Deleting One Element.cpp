//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 1;
        int startPos = 0, endPos;
        for(endPos = 0; endPos < (int)nums.size(); endPos++){
            if(nums[endPos] == 0)k--;
            if(k < 0 and nums[startPos++] == 0){
                k++;
            }
        }
        return endPos - startPos - 1;
    }
};
