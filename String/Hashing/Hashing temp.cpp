/*
 *Polynomial hashing
 *Call Hash A(string , len, base, mod)
 */
struct Hash{
    int len, base; long long mod;
    string s;
    std::vector<int>p, h;
    //Hash(){}
    // O(n)
    Hash(string s, int len, int base, int mod) : s(s), len(len), base(base), mod(mod) {
        p.resize(len + 1, 0); //base^i (mod mods)
        h.resize(len + 1, 0); // hash of prefix of length i
        p[0] = 1;
        for(int i = 1; i <= len; i++) {
            p[i] = (1LL * p[i - 1] * base) % mod;
            h[i] = (1LL * h[i - 1] * base + (int)s[i - 1]) % mod;
        }
    }
    /*
     *Returns hash of the substring of length len starting at pos. i
     *O(1)
     */
    int substr(int l, int r) {
        return (h[r] - (1LL * h[l - 1] * p[r - l + 1]) % mod + mod) % mod;
    }
};
