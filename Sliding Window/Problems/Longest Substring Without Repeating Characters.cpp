//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>mp;
        int startPos = 0;
        int maxLength = 0;
        for(int endPos = 0; endPos < s.size(); endPos++){
            mp[s[endPos]]++;
            
            while(mp[s[endPos] ] > 1) {
                   mp[s[startPos++] ]--;
            }
            maxLength = max(maxLength, endPos - startPos + 1);
        }
        return maxLength;
    }
};
