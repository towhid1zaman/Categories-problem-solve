//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        map<char, int>Cnt;
        int startPos = 0;
        for(int endPos = 0; endPos < s.size(); endPos++){
            Cnt[ s[endPos ]]++;
            while(Cnt.size() > k){
                Cnt[ s[startPos] ]--;
                if(Cnt[ s[startPos] ] == 0){
                    Cnt.erase(s[startPos]);
                }
                startPos++;
             }
             if(Cnt.size() == k)ans = max(ans, endPos - startPos + 1);
            }
            return ans;
        }

};

