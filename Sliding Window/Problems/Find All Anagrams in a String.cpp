//https://leetcode.com/problems/find-all-anagrams-in-a-string/
//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = (int)s.size();
        int k = (int)p.size();
        if(k > n)return {};
        
        int startPos = 0;
        vector<int>pos;
        
        unordered_map<char,int>countChar;
        
        for(int i = 0; i<k; i++){
            countChar[p[i]]++;
        }
        
        int totalCount = (int)countChar.size();
        for(int endPos = 0; endPos < n; endPos++){
            if(countChar.find(s[endPos])!=countChar.end()){
                countChar[s[endPos]]--;
                if(countChar[ s[endPos] ] == 0)totalCount--;
            }
           if(endPos - startPos + 1 == k){
                if(totalCount == 0){
                    pos.push_back(startPos);
                }
                if(countChar.find(s[startPos]) != countChar.end()){
                    countChar[s[startPos]]++;
                    if(countChar[ s[startPos] ] == 1)totalCount++;
                }
                startPos++;
            }
        }
        return pos;
    }
};
