//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int startPos = 0, endPos = (int)height.size() - 1;
        int maximumArea = 0;
        while(startPos < endPos){
            int area = (endPos - startPos) * min(height[startPos], height[endPos]);
            maximumArea = max(area, maximumArea);
            if(height[startPos] <= height[endPos])startPos++;
            else endPos--;
        }
        return maximumArea;
    }
};
