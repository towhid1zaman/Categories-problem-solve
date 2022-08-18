//https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = (int)nums.size();
        int startPos = 0, endPos = n - 1, curPos = n - 1;
        vector<int>ans(n, 0);
        while(curPos >= 0){
            if( abs(nums[startPos])  > abs(nums[endPos]) ){
                ans[curPos--] = nums[startPos] * nums[startPos++];
            }
            else ans[curPos--] = nums[endPos] * nums[endPos--];
        }
        return ans;
    }
};
