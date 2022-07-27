//https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = -1;
        int startPos = 0;
        map<char, int>sCnt;
        int maxChar = -1;
        for(int endPos = 0; endPos < (int)s.size(); endPos++){
            sCnt[ s[endPos] ]++;
            maxChar = max(maxChar, sCnt[ s[endPos] ]);
            
            while( (endPos - startPos + 1) - maxChar > k){
                sCnt[ s[startPos] ]--;
                startPos++;
            }
            
            ans = max(ans, endPos - startPos + 1);
        }
        
        return ans;
    }
};
