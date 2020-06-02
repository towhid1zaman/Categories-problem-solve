
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;



/*

You are given two  numbers:
last digit of m^n , range(<=10^101)
m and n both are not 0. You have to find the last digit of m^n.

*/


int main(){
        string a,b;
        while(cin>>a>>b){
            if(a=="0" and b=="0")break;
            int len1  = a.length();
            int len2  = b.length();

            int m = a[len1-1]-'0';
            int n = b[len2-1]-'0';
            if(len2>1){
                n = n + (b[len2-2]-'0')*10;
            }
            if(n%4==0) n = 4;
            else n = n%4;

            int res = (int)pow(m,n)%10;
            cout << res << endl;

        }

return 0;
}
