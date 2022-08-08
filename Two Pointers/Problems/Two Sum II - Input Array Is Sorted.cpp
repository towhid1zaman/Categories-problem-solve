//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        int startPos = 0, endPos = a.size() - 1;
        vector<int>ans;
        while(startPos < endPos){
            if(a[startPos] + a[endPos] > target) endPos--;
            else if(a[startPos] + a[endPos] < target)startPos++;
            else if(a[startPos] + a[endPos] == target){
                ans.push_back(startPos + 1);
                ans.push_back(endPos + 1);
                break;
            }
        }
        return ans;
    }
};
