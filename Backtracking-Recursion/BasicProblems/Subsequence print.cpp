
/*
    Given an integer array nums of unique elements, return  all possible subsequence (the power set).
    total subsets = 2^N
*/
class Solution {
public:

    vector<vector<int>>subsequall;
    void printSubsequ(vector<int>nums, int pos, int n, vector<int> ans){
        subsequall.push_back(ans);
        for(int i = pos; i<n; i++){
            if(i > pos and nums[i-1] == nums[i])continue;
            ans.push_back(nums[i]);
            printSubsequ(nums, i+1, n, ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        vector<int>a;
        printSubsequ(nums, 0, n, a);
        return subsequall;
    }
};
