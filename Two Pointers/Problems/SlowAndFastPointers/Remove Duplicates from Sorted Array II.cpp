class Solution {//80. Remove Duplicates from Sorted Array II
public:
    int removeDuplicates(vector<int>& nums) {
        int startPos = 0;
        for(auto num:nums){
            if(startPos < 2 or num > nums[startPos-2]){
                nums[startPos++] = num;
            }
        }
        return startPos;
    }
};
