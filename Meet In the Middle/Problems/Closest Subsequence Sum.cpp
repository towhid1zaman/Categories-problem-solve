/*
Main idea is to generate all subset sum , hence n is nearly 40, so its not possible to generate 2^40 subset
sum, So we can devide whole array into two parts, then separately generate subset sum.

Lets say goal = sum1 + sum2

Then simply take one sum1 from left part and (goal - sum1), that is sum2 from second part, and minimize
the answer.

https://leetcode.com/problems/closest-subsequence-sum/
*/

class Solution {
public:
    
    vector<int>generateSubsetSum(vector<int>nums){
        int n = nums.size();
        vector<int>subsetSum;
        // using bitmask for subset sum, atmost 2^n subset possible
        for(int mask = 0; mask < (1 << n); mask++){
            int sum = 0;
            
            // traversing through array
            for(int bit = 0; bit < n; bit++){
                // if ith bit is set then keep it in answer
                if(mask & (1<<bit)){
                    sum += nums[bit];
                }
            }
            
            //storing subset sum according to their subset size
            
            subsetSum.push_back(sum);
        }
        return subsetSum;
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<int>temp;
        int i = 0;
        for(; i<nums.size()/2;i++){
            temp.push_back(nums[i]);
        }
        vector<int>left = generateSubsetSum(temp);
        
        vector<int>temp2;
        for(; i<nums.size(); i++){
            temp2.push_back(nums[i]);
        }
        vector<int>right = generateSubsetSum(temp2);
        sort(right.begin(), right.end());
        
        int ans = INT_MAX;
        for(int &a : left){
            int b = goal - a;
            auto it = lower_bound(right.begin(), right.end(), b);
            if(it != right.end()){
                b = *(it);
                ans = min(ans, abs(goal - (a+b)));
            }
            if(it!=right.begin()){
                b = *(--it);
                ans = min(ans, abs(goal - (a+b)));
            }

        }
        return ans;
    }
};
