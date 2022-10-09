class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int startPos = 0, endPos = (int)nums.size() - 1;
        while(startPos <= endPos){
            int mid = startPos + (endPos - startPos)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                endPos = mid - 1;
            }
            else startPos = mid + 1;
        }
        return startPos;
    }
};
