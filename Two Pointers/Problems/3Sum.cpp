//https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i<(int)nums.size() - 1; i++){
            if(i>0 and nums[i] == nums[i-1])continue; //avoid duplicates
            int startPos = i+1, endPos = (int)nums.size() - 1;
            while(startPos < endPos){
                int sum = nums[i] + nums[startPos] + nums[endPos];
                if(sum < 0)startPos++;
                else if(sum > 0)endPos--;
                else{
                    ans.push_back(vector<int>{nums[i], nums[startPos], nums[endPos]});         
                    while(startPos + 1 < endPos and nums[startPos] == nums[startPos+1]) startPos++; //avoid duplicates
                    while(endPos - 1 > startPos and nums[endPos] == nums[endPos-1]) endPos--; //avoid duplicates;
                    startPos++, endPos--;
                }
            }
        }
        return ans;
    }
};
