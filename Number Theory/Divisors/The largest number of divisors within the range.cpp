/*
 We need to find the number within the range
 from L to U with the largest number of divisors.

 approach:
        we need to findout number of divisors till sqrt(n),
        then if sqrt(n) is integer then simply , total divisors is = div*2;
        otherwise if sqrt(n) is non-integer , then total divisors is = div*2 -1;

*/

// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int divisors(int n){
    int cnt = 0;
    for(int i = 1; i<=sqrt(n); i++){
        if(n%i==0)cnt++;
    }
    int sq = sqrt(n);
    if(sq==sqrt(n)){
        cnt = cnt*2-1;
    }
    else cnt = cnt*2;

    return cnt;
}


int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);

        int T; cin >> T;
        while(T--){
            int mx=0,num;
            int L, U; cin >> L >> U;

            for(int Number = L; Number<=U; Number++){
                int res = divisors(Number);
                if(res>mx){
                    mx = res;
                    num = Number;
                }
            }
            printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U,num, mx);
        }




return 0;
}

