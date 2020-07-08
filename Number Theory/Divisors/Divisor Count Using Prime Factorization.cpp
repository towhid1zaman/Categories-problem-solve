//quick sieve
bool checkprime[maxn + 5];
vll vc;
void sieve() {///false means prime
    vc.pb(2);
    checkprime[0]=true;
    checkprime[1]=true;
    for (ll i = 3; i <= maxn; i += 2) {
        if (!checkprime[i]) {
            vc.pb(i);
            for (ll j = i * i; j <= maxn; j += (i + i))
                checkprime[j] = true;
        }
    }
}
//DivisorCount using primefactorization
void divisor(ll n){
    ll ans = 1;
    for(ll i = 0; i<prime.size() and prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            ll cnt = 0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1)ans*=2;
    return ans;
}
