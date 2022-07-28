//https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t.size() > s.size() or s.empty()){
            return "";
        }
        
        int startPos = 0;
        int leftPos = 0, rightPos = (int)s.size() - 1;
        int minLength = (int)s.size();
        
        map<char, int>charCount;
        
        for(int i = 0; i<t.size(); i++){
            charCount[ t[i] ]++;
        }
        
        int distinct = charCount.size();
        bool found = false;
        for(int endPos = 0; endPos < s.size(); endPos++){
            if(charCount.find(s[ endPos ]) != charCount.end()) {
                charCount[ s[endPos] ]--;
                if(charCount[ s[endPos] ] == 0)distinct--;
            }
            
          if(distinct > 0)continue;
            
            while(distinct == 0) {
                if (charCount.find(s[ startPos ]) != charCount.end()) {
                    charCount[ s[startPos] ]++;
                    if (charCount[ s[startPos] ] ==1 ) distinct++;
                }
                startPos++;
            }
            
            if (endPos - startPos < minLength) {
                leftPos = startPos;
                rightPos = endPos;
                minLength = endPos - startPos;
                found = true;
            }
            
        }
        if (found) {
            string ans ="";
            for(int i = leftPos-1; i<=rightPos; i++){
                ans += s[i];
            }
            return ans;
            
           // return s.substr(left-1, right)
        }else {
            return "";
        }
    }
};
