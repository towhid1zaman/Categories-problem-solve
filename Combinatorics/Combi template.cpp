// example : http://p.ip.fi/Hr6-

struct Combinatorics{
    ll fact[maxn],inv[maxn];
 
    ll BigMod(ll b,ll p,ll m){
        ll ret = 1;
        while(p > 0){
            if(p&1)ret = (ret * b) % m;
            p = p >> 1;
            b = (b * b) % m;
        }
        return ret;
    }
 
    void Build(ll n){
        fact[0] = 1;
        for(int i = 1;i <= n+2;i++){
        	fact[i] = (fact[i - 1] * i) % mod;
        }
        for(int i = 0;i <= n+2;i++){
        	inv[i] = BigMod(fact[i],mod-2,mod);
        }
    }
 
    ll Choose(ll n,ll r){
        if(n < r)return 0;
        ll u = fact[n];
        ll v = (inv[r] * inv[n - r]) % mod;
        return (u * v) % mod;
    }

    ll Factorial(ll n){
    	return fact[n];
    }

}combi;
