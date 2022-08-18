//https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int even = 0, odd = 1, n = (int)nums.size();
        vector<int>ans(n, 0);
        for(auto num:nums){
            if(num > 0){
                ans[even] = num;
                even+=2;
            }
            else if(num < 0){
                ans[odd] = num;
                odd+=2;
            }
        }
        return ans;
    }
};
