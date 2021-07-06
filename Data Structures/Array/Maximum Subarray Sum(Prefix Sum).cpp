class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        std::vector<long long>prefS;
        for(int i = 0; i<n; i++){
            long long  a = nums[i];
            if(!i)prefS.push_back(a);
            else{
                a+=prefS.back();
                prefS.push_back(a);
            }
        }

        long long cur_min = 0, ans = INT_MIN;
        for(int i = 0; i<n; i++){
            ans = max(ans, prefS[i] - cur_min);
            cur_min = min(prefS[i], cur_min);
        }
        return ans;
    }
};
