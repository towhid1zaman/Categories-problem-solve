/*
given given 3 integer N, K, Q. Where N is size of array, K is initial value of each element of array.
Q is a query, each query given an integer v, v is the position of array.
we have to do that each operation except position v, all elements value is decrease by 1

after  Query finish , we have to tell, each position is greater than 0 or not.

*/


// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;


int main(){
        _
        int  n,k,q; cin >> n >> k >>  q;
        vi a(n+1,k);
        for(int i = 1; i<=q; i++){
            int v; cin >> v;
            a[v]++;
        }
        for(int i = 1; i<=n; i++){
            if(a[i]>q)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }



return 0;
}
/*
6 3 4
3
1
3
2

No
No
Yes
No
No
No



*/

