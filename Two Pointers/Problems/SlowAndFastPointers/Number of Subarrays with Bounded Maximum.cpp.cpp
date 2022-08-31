//https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans = 0;
        int startPos = -1, endPos = -1;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > right)startPos = i;
            if(nums[i] >= left)endPos = i;
            ans += endPos - startPos;
        }
        return ans;
    }
};
