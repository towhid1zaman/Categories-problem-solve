//https://leetcode.com/problems/sort-colors/

//without two pointers

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(int i = 0; i< (int)nums.size(); i++){
            zero += (nums[i] == 0);
            one += (nums[i] == 1);
            two += (nums[i] == 2);
        }
        int startPos = 0;
        while(zero--) nums[startPos++] = 0;
        while(one--) nums[startPos++] = 1;
        while(two--) nums[startPos++] = 2;
    }
};

// with two pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int startPos = 0, endPos = (int)nums.size() - 1, curPos = 0;
        
        while(curPos <= endPos){
            if(nums[curPos] == 0){
                swap(nums[curPos++], nums[startPos++]);
            }
            else if(nums[curPos] == 1){
                curPos++;
            }
            else if(nums[curPos] == 2){
                swap(nums[curPos], nums[endPos--]);
            }
        }
    }
};
