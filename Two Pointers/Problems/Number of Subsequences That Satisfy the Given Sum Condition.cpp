//https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
class Solution {
public:
    int mod =(int)1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int ans = 0, n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int startPos = 0, endPos = n - 1;
        // a[i] + a[j] <=target, then there are 2^(j-i) subsequences
        vector<int>power(n, 1);
        for(int i = 1; i<n; i++){
            power[i] = power[i-1] * 2 % mod;
        }
        while(startPos <= endPos){
            if(nums[startPos] + nums[endPos] > target)endPos--;
            else{
                ans = ( ans + power[endPos - startPos]) % mod;
                startPos++;
            }
        }
        return ans;
    }
};
