//https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1
int minSwaps(int arr[], int n) {
    
    // Complete the function
    int ones = 0, curOne = 0;

    for(int i = 0; i<n; i++){
        ones += arr[i];
    }
    if(ones == 0)return -1;
    int startPos = 0;    
    int ans = 0;
    for(int endPos = 0; endPos < n; endPos++){
        curOne += arr[endPos];
        
        if(endPos - startPos + 1 == ones){
            ans = max(ans, curOne);
            if(arr[startPos] == 1){
                curOne--;
            }
            startPos++;
        }
    }
    return ones - ans;
}
