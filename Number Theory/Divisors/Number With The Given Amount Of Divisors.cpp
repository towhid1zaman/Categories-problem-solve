int n;
std::vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41};
 
ll go(int nod, ll cur_n, int pos){
    if(nod == n)return cur_n;
 
    ll ans = maxn;
    for(int e = 1; ;e++){
        cur_n *= primes[pos];
        if(cur_n > ans or ( nod*(e+1) > n))break;
        ans = min(ans, go( (nod*(e+1) ), cur_n, pos+1) );
    }
    return ans;
}
void task(){
    cin >> n;
    ll ans = go(1,1,0);
    cout << ans << endl;
}
