namespace String_Matching{
    /*Z-Algo, build an array size of string s
     *In each element of array it store an element that says
     *exactly 'x' size of substring can be found from this position 
     *that is equal to Prefix of given string.
     */
    std::vector<int> z_function(string s){
        int n = (int) s.length();
        std::vector<int> z(n, 0);
        //z[0] = n; //whole string is a substring of itself.
        for (int i = 1, l = 0, r = 0; i < n; ++i){
            if (i <= r)
                z[i] = min (r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }

    /*Given a string S (with length N) and a pattern P (with length M),
     *KMP, finds all the occurrence of P in S
     */
    std::vector<int> prefix_function(string s){
        int n = (int)s.length();
        std::vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }

    std::vector<int> KMP_match(string text, string pattern, std::vector<int>&pi){
        int n = (int)text.length(), m = (int)pattern.length();
        std::vector<int> Prefix = pi;
        std::vector<int>Match_position;
        int j = 0, i = 0;
        // i = text, j = pattern
        while (i < n) {
            if (text[i] == pattern[j]) ++i, ++j;
            else {
                if (j != 0) j = Prefix[j - 1];
                else ++i;
            }
            if (j == (int) pattern.length()) {
                Match_position.push_back(i-m);
                j = Prefix[j-1];
            }
        }
        return Match_position;
    }
    /*Counting the number of occurrences of each prefix
     *occur(given string, prefix value)
     */
    std::vector<int> occur(string s, std::vector<int>&pi){
        int n = (int)s.length();
        std::vector<int>ans(n+1, 0);
        for (int i = 0; i < n; i++)ans[pi[i]]++;
        for (int i = n-1; i > 0; i--)ans[pi[i-1]] += ans[i];
        for (int i = 0; i <= n; i++)ans[i]++;

        return ans;
    }

    //check range, 0 indexed
}using namespace String_Matching;
