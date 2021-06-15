//https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    string s;
    int dp[1001][1001];
    pair<int, int> nxt[1001][1001];

    int go(int b, int e){
        if(b==e)return 1;
        if(b > e)return 0;
        if(dp[b][e] != -1)return dp[b][e];
        if(s[b] == s[e]){
            nxt[b][e] = {b+1, e-1};
            return dp[b][e] = go(b+1, e-1) + 2;
        }
        else{
            int v1 = go(b+1, e);
            int v2 = go(b, e-1);
            if(v1 > v2){
                nxt[b][e] = {b+1, e};
            }
            else{
                nxt[b][e] = {b, e-1};
            }

            return dp[b][e] = max(v1,v2);
        }
    }
    int longestPalindromeSubseq(string t) {
        s = t; 
        memset(dp, -1, sizeof(dp));
        int n = (int)t.size();
         return go(0, n-1);
    }
};
