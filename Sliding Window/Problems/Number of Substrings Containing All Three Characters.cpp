//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>charCount(3, 0);
        int startPos = 0;
        int ans = 0;
        for(int endPos = 0; endPos < s.size(); endPos++){
            charCount[s[endPos]-'a']++;
            while(charCount[0] and charCount[1] and charCount[2]){
               charCount[ s[ startPos++ ] - 'a']--;
            }
            ans += startPos;
        }
        return ans;
    }
};
