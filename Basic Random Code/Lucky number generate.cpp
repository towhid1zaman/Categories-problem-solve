void GenerateLucky(ll n){
    if(n>1000000000000LL)return;
    if(n!=0)lucky.pb(n);
    GenerateLucky(n*10+4);
    GenerateLucky(n*10+7);
}
