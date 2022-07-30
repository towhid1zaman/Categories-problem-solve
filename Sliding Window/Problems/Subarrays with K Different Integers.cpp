class Solution {
public:
    int AtMostKSubArray(vector<int>&s, int k){
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
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return AtMostKSubArray(nums, k) - AtMostKSubArray(nums, k-1);
    }
    
};
