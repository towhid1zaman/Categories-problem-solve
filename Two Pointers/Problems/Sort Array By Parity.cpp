//https://leetcode.com/problems/sort-array-by-parity/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = (int)nums.size();
        int startPos = 0, curPos = 0;
        while(curPos < n){
            if(nums[curPos]%2==0){
                swap(nums[startPos++], nums[curPos++]);
            }
            else curPos++;
        }
        return nums;
    }
};
