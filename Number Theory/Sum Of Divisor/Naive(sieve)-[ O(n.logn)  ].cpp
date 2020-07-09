
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define MAXN 500000

int sum[MAXN+1];

void sieve()
{
  int i, j;
  for( i = 1; i <= MAXN; ++i)
    for( j = i+i; j <= MAXN; j += i) sum[j] += i;
}

void task(){
    int n;
    cin >> n;
    cout <<sum[n]<<endl;
}

int main(){
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif
        sieve();
        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
return 0;
}


