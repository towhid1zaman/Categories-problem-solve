//https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int startPos = 0, endPos = n-1;
        while(startPos <= endPos){
            int temp = nums[endPos];
            nums[endPos] = nums[startPos];
            nums[startPos] = temp;
            startPos++, endPos--;
        }
        
        k = k%n;
        
        startPos = 0, endPos = k-1;
        while(startPos <= endPos){
            int temp = nums[endPos];
            nums[endPos] = nums[startPos];
            nums[startPos] = temp;
            startPos++, endPos--;
        }
        startPos = k, endPos = n-1;
        while(startPos <= endPos){
            int temp = nums[endPos];
            nums[endPos] = nums[startPos];
            nums[startPos] = temp;
            startPos++, endPos--;
        }
    }
};
