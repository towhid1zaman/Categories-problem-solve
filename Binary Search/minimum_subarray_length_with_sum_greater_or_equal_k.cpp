#include<bits/stdc++.h>
using namespace std;
int a[10000];
int binary_search(int k,int L,int n)
{
    int lo = L,hi=n,R = -1;
    while(lo<=hi){
        int mid = (lo+hi)>>1;
        if(a[mid] - a[L-1]>=k){
            R = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return R;
}
int main()
{
        int n,k;
        cin>>n>>k;
        for(int i = 1; i<=n;i++){
            cin>>a[i];
            a[i]+=a[i-1];
        }
        int min_length = n+5;
        for(int L = 1; L<=n;L++){
            int R = binary_search(k,L,n);
            if(R==-1){
                break;
            }
            min_length = min(min_length,R-L+1);
        }
        cout<<min_length<<endl;

        return 0;
}
