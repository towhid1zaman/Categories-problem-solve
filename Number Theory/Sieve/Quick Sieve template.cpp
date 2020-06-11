int p[10000005];

void sieve(){
    for(ll i=2;i<=10000000;i++){
        if(p[i]==0)
        for(ll j=i*i;j<=10000000;j+=i){
            if(p[j]==0)
            p[j]=i;
        }
    }
}
