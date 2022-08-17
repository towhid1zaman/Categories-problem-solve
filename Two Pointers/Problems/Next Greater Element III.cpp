class Solution {
public:
    int nextGreaterElement(int N) {
        string s = to_string(N);
        int startPos, endPos;
        int n = (int)s.size();
        for(int i = n-2; i>=0; i--){
            if(s[i] < s[i+1]){
                startPos = i;
                break;
            }
        }
        if(startPos < 0)return -1;
        for(int i = n-1; i>=0; i--){
            if(s[i] > s[startPos]){
                endPos = i;
                break;
            }
        }
        swap(s[startPos], s[endPos]);
        sort(s.begin()+startPos+1, s.end());
        
        long long ans = (long long)(stol(s));
        if(ans > INT_MAX)return -1;
        else return ans;
    }
};
