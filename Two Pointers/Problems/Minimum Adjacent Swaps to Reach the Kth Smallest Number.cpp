//https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
class Solution {
public:
    void nextPermutation(string &a) {
    	int n = (int)a.size();
        int startPos, endPos;
        for(int i = n-2; i>=0; i--){
            if(a[i] < a[i+1]){
                startPos = i;
                break;
            }
        }
        if(startPos < 0){
            reverse(a.begin(), a.end());
        }else{
            for(int i = n-1; i>=0; i--){
                if(a[i] > a[startPos]){
                    endPos = i;
                    break;
                }
            }
            swap(a[startPos], a[endPos]);

            reverse(a.begin()+startPos+1, a.end());
        }
    }
    int getMinSwaps(string num, int k) {
        string perm = num;
        while(k--){
            nextPermutation(perm);
        }
        int ans = 0;
        for(int i = 0; i<num.size(); i++){
            int j = i+1;
            while(num[i] != perm[i]){
                ans++;
                swap(perm[i], perm[j++]);
            }
        }
        return ans;
    }
};
