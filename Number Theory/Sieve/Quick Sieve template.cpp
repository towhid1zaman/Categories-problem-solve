int p[10000005];
void sieve(){
    p[2] = 1;
    for(ll i = 3; i<=10000000; i+=2){
        p[i] = 1;
    }
    for(ll i=3;i<=10000000;i+=2){
        if(p[i]==1){
            for(ll j=i*i;j<=10000000;j+=2*i){
                p[j] = 0;
            }
        }
    }
}
