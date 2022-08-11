//https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans = 0, dif = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < (int)nums.size() - 1; i++){
            int startPos = i + 1, endPos =  (int)nums.size() - 1;
            
            while(startPos < endPos){
                int sum = nums[i] + nums[startPos] + nums[endPos];
                int curDif = abs( sum - target );
                if(curDif < dif){
                    ans = sum, dif = curDif;
                }
                if(sum ==  target){
                    i = (int)nums.size() - 1;
                    break;
                }
                if(sum < target) startPos++;
                else if(sum > target) endPos--;
            }
        } 
        
        return ans;
    }
};
