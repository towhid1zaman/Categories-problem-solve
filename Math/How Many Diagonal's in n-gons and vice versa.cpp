
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
        ll n;
        while(cin >> n){
            if(n==0)break;
            ll diagonal = ( n*(n-3) )/ 2;
            ll gons = ceil( (3 + sqrt(9+(8*n)))/2   );
            cout << diagonal <<' '<< gons << endl;
        }


return 0;
}

/*
how many diagonal in n-gons = n*(n-3)/2 ;

if we cant do its opposite we can find gon's 
    
    its just ax^2+bx+c=0 formula.
    x = -b+sqrt(b^2 - 4ac) / 2a // taking positive
    see, n*(n-3)/2 = c(its given)
            => n^-3n - 2c = 0

*/


