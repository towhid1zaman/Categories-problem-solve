// https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int atmostK(vector<int>& nums, int k){
        int ans = 0; int startPos = 0;
        int sum = 0;
        for(int endPos = 0; endPos < (int)nums.size(); endPos++){
            k -= nums[endPos]%2;
            while(k < 0){
                k += nums[startPos++]%2;
            }
            ans+= endPos - startPos + 1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostK(nums, k) - atmostK(nums, k-1);
    }
};
