//https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
//https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       int maxLength = 0;
       int sum = 0;
       map<int, int>startPos;
       startPos[0] = -1;
     
       for(int endPos = 0; endPos < N; endPos++){
           sum += A[endPos];
           
           if(startPos.find(sum) == startPos.end()){
               startPos[sum] = endPos;
           }
           if(startPos.find(sum - K) != startPos.end()){
               maxLength = max(endPos - startPos[sum - K], maxLength);
           }
       }
       return maxLength;
       
    } 

};
