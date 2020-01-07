*/
    CF: Tman
*/
#include "bits/stdc++.h"
using namespace std;
#define ll long long

/*
// iterative way
int exp(int x,int n){
    int res = 1;
    while(n>0){
        res = res*x;
        n--;
    }
    return res;
}
*/

/* recursive way */
int exp(int x,int n){
    if(n==0){
        return 1;
    }
    return x*exp(x,n-1);
}
int main()
{
    int x,n;
    while(cin>>x>>n){
        cout<<"The Exponentiation is: "<<exp(x,n)<<endl;
    }

return 0;
}



