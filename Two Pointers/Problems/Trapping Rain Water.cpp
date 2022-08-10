//https://leetcode.com/problems/trapping-rain-water/submissions/

// Two pointer solution { O(n) TC, and O(1) SC)

class Solution {
public:
    /*The key idea is to solve the problem is the track the maxvalue from left to
     *right pointer, and right to left pointer.
     *Then every for height sum the 
     *min(Max left value so far, max rigt value so far) - current height
     *Current height is minimum of left max and right max, and move pointer
     *according to them(whose value is small)
     *
     */
    int trap(vector<int>& height) {
        
        int startPos = 0, endPos = (int)height.size()-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while(startPos < endPos){
            leftMax = max(leftMax, height[startPos]);
            rightMax = max(rightMax, height[endPos]);
            
            if(leftMax <= rightMax){
                ans += max(min(leftMax, rightMax) - height[startPos], 0);
                startPos++;
            }
            else{
                ans += max(min(leftMax, rightMax) - height[endPos], 0);
                endPos--;
            }
        }
        return ans;
    }
};
