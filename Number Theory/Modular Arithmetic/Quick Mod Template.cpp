
inline ll MOD(ll x)
{
    ll y = x % mod;
    return (y >= 0) ? y: y+mod; // if -ve, simply add M
}
// if we want to calculate mod inverse, then simply we pass m-2
ll modexpo(ll x, ll n, ll m)
{
    ll res = 1;
    while(n){
        if(n & 1LL) res = (res*x) % m;
        x = (x*x) % m;
        n >>= 1;
    }
    return res;
}
