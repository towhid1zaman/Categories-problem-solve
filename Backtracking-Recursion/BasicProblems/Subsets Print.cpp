
/*
    Given an integer array nums of unique elements, return  all possible subsets (the power set).
    total subsets = 2^N

*/

class Solution {
public:
    vector<vector<int>>suball;
    void printSubsets(vector<int>nums, int pos, int n, vector<int> ans){
        if(pos >= n){
            suball.push_back(ans);
            return;
        }
        //take
        ans.push_back(nums[pos]);
        printSubsets(nums, pos+1, n, ans);
        
        //dont take
        ans.pop_back();
        printSubsets(nums, pos+1, n, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int>a;
        printSubsets(nums, 0, n, a);
        return suball;
    }
};

