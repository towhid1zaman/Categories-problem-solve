//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string s;
    int dp[1001][1001];
    int go(int b, int e){
        if(b >= e)return 1;

        if(dp[b][e]!=-1)return dp[b][e];

        if(s[b] == s[e]){
            return dp[b][e] = go(b+1, e-1);
        }
        else return dp[b][e] = 0;
    }
    string longestPalindrome(string t) {
        s = t;
        memset(dp, -1, sizeof(dp));
        int n = (int)t.size();
        int ans = 0;
        string ans_str = "";
        for(int i = 0; i<(int)s.size(); i++){
            string b;b.clear();
            for(int j = i; j<(int)s.size(); j++){
                b.push_back(s[j]);
                if(go(i, j)){
                    if(ans_str.size() < b.size())ans_str = b;
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans_str;
    }
};
