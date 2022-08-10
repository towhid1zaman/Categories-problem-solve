//https://leetcode.com/problems/3sum-with-multiplicity/
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = (int)1e9+7;
        int ans = 0;
        unordered_map<int, int>markValue;
        for(int endPos = 0; endPos<(int)arr.size(); endPos++){
             ans = (ans + markValue[target - arr[endPos]] )%mod;
            for(int startPos = 0; startPos < endPos; startPos++){
                markValue[arr[startPos] + arr[endPos]]++;
            }
        }
        return ans;
    }
};
