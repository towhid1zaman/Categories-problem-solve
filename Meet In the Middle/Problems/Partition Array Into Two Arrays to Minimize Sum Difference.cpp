/***
* Maximum size of array could be 2*15 = 30
* Total subset (2^n)-1 = (2^30) - 1 = 1073741823, this is huge
* So, we cant't generate all subset sum at the same time. We can separate whole array into two part.
* Then We can generate subset sum and store all subset sum according to their size.
* Subset Sum will store into 2D vector, each subarray size their sum will be store their.
* 
* First, take total sum of whole array, totalSum = sumOf(Array's elements)
* Now, traverse the left part, then for each subsetSize vectors element lets say it 'a', 
* for 'a' we need to search 'b', that can be found from right part 
*  
* Now we have totalSum of array, and 'a'
* 
*   totalSum = 2(a+b)
* =>totalSum = 2a + 2b 
* =>2b = totalSum - 2a
* =>b = (totalSum - 2a)/2
* 
*
* So, we need lower bound of 'b' from left part. 
*
* at the end just minimize the ans by,
* ans = min(ans, totalSum - 2(a+b))
*
*
*
****/


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = (int)nums.size()/2;
        vector<int>left[n+1], right[n+1]; // separate two parts and strong their subset sum
        
        // using bitmask for subset sum, atmost 2^n subset possible
        for(int mask = 0; mask < (1 << n); mask++){
            int subsetSize = 0, leftSubsetSum = 0, rightSubsetSum = 0;
            
            // traversing through array
            for(int bit = 0; bit < n; bit++){
                // if ith bit is set then keep it in answer
                if(mask & (1<<bit)){
                    subsetSize++, leftSubsetSum += nums[bit], rightSubsetSum += nums[bit + n];
                }
            }
            
            //storing subset sum according to their subset size
            
            left[subsetSize].push_back(leftSubsetSum);
            right[subsetSize].push_back(rightSubsetSum);
        }
        
        int totalSum = 0;
        for(int num:nums)totalSum += num;
        
        int ans = INT_MAX;
        
        for(int i = 0; i <=n; i++){
            vector<int> rightSub = right[n-i];
            sort(rightSub.begin(), rightSub.end());
            
            for(int &a:left[i]){
                int b = (totalSum - 2*a)/2;
                auto it = lower_bound(rightSub.begin(), rightSub.end(), b);
                if(it != rightSub.end()){
                    b = *it;
                    ans = min( ans, abs(totalSum - 2*(a+b) ));
                }
            }
        }
        
        return ans;
    }
};
