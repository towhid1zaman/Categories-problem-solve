//https://leetcode.com/problems/sort-array-by-parity-ii/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1, n = (int)nums.size();
        while(odd < n and even < n){
            if(nums[even]%2 == 0){
                even+=2;
            }
            else if(nums[odd]%2 == 1){
                odd+=2;
            }
            else{
                swap(nums[even], nums[odd]);
            }
        }
        return nums;
    }
};
