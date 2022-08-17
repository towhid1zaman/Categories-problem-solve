class Solution {
public:
    void nextPermutation(vector<int>& a) {
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
}; 
