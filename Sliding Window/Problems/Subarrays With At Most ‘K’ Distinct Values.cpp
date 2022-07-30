//https://www.codingninjas.com/codestudio/problems/subarrays-with-at-most-k-distinct-values_1473804

#include<map>
int longestAtMostKSubArray(vector<int>&s, int k){
        int ans = 0;
        map<int, int>Cnt;
        int startPos = 0;
        
        for(int endPos = 0; endPos < s.size(); endPos++){

            Cnt[ s[endPos ]]++;
            
            while(Cnt.size() > k){
                Cnt[ s[startPos] ]--;
                if(Cnt[ s[startPos] ] == 0){
                    Cnt.erase(s[startPos]);
                }
                startPos++;
             }
             ans += endPos - startPos + 1;
            }
            return ans;
        }
int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    return longestAtMostKSubArray(arr, k);
}
