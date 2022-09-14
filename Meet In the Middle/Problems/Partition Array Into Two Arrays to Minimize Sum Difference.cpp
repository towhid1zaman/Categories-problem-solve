class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int totalSize = (int)nums.size();
        int n = totalSize/2;
        
        vector<int>left[n+1], right[n+1];
        
        for(int mask = 0; mask < (1<<n); mask++){
            int leftSubSum = 0, rightSubSum = 0;
            int subSize = 0;
            
            for(int bit = 0; bit < n; bit ++){
                if(mask & (1 << bit)){
                    subSize++, leftSubSum += nums[bit], rightSubSum += nums[bit + n];
                }
            }
            left[subSize].push_back(leftSubSum);
            right[subSize].push_back(rightSubSum);
        }
        
        int totalSum = 0;
        for(auto num:nums)totalSum += num;
        
        int ans = INT_MAX;
        
        for(int i = 0; i<=n; i++){
            vector<int>rightSub = right[n - i];
            sort(rightSub.begin(), rightSub.end());
 
            for(auto &a:left[i]){   
                int b = (totalSum - 2*a)/2;
                /*
                     total = 2(a + b) // a = from left part, b = from right part {a+b == n size}
                  => total = 2a + 2b
                  => 2b = total - 2a
                  => b = (total - 2a)/2

                */
                auto itr = lower_bound(rightSub.begin(), rightSub.end(), b);
                if(itr != rightSub.end()){
                    b = *itr;
                    ans = min(ans, abs(totalSum - 2*(a + b)));
                }
            }
        }
        return ans;
    }
};
