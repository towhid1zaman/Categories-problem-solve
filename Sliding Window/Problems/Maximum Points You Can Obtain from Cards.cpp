//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int curSum = 0;
        for(int i = 0; i<k; i++){
            curSum += cardPoints[i];
        }
        
        ans = curSum;
        
        int startPos = k-1;
        int endPos = (int)cardPoints.size() - 1;
        while(startPos >=0){
            curSum -= cardPoints[startPos];
            curSum += cardPoints[endPos];
            ans = max(ans, curSum);
            endPos--;
            startPos--;
        }
        
        return ans;
    }
};
