//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, curSum = 0;
        int startPos = 0;
       
        for(int endPos = 0; endPos < (int)arr.size(); endPos++){
            curSum += arr[endPos];
            if(endPos - startPos + 1 == k){
                int avg = curSum/k;
                if(avg >= threshold) ans++;
                curSum-=arr[startPos++];
            }
        }
        return ans;
    }
};
