//https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int sum = 0;
        for(int i = 0; i<K; i++){
            sum += Arr[i];
        }
        int mx_sum = sum;
        for(int i = 1; i+K-1<N; i++){
            sum -= Arr[i-1];
            sum += Arr[i+K-1];
            mx_sum = max(sum, mx_sum);
        }
        return mx_sum;
    }
};
