//https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector< vector<int> >ans;
        if( (int)nums.size() < 4)return ans; 
        sort(nums.begin(), nums.end());

        for(int i = 0; i<(int)nums.size(); i++){
            
            if(i > 0 and nums[i] == nums[i-1])continue; //avoid duplicates
            long long newT = target - nums[i];
            for(int j = i + 1; j < (int)nums.size(); j++){
                
                if(j > i + 1 and nums[j] == nums[j-1])continue;//avoid duplicates
            
                long long newTarget = newT - nums[j];
                int startPos = j + 1, endPos = (int)nums.size() - 1;
                while(startPos < endPos){
                    long long  sum = nums[startPos] + nums[endPos];
                    if(sum < newTarget)startPos++;
                    else if(sum > newTarget)endPos--;
                    else{
                        ans.push_back({nums[i], nums[j], nums[startPos], nums[endPos]});
                        while(startPos < nums.size() - 1 and nums[startPos] == nums[startPos + 1])startPos++;//avoid duplicates
                        while(endPos > 0 and nums[endPos] == nums[endPos - 1])endPos--;//avoid duplicates
                        startPos++, endPos--;
                    }
                }
            }
        }
        return ans;
    }
};
