

// </> : towhid1zaman

//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("avx,avx2,fma") 
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

/*finding pivot point on sorted rotated array using binary search
 *first sorted in increasing order thenanother sorted array
 *example : 1 2 3 4 2 3
 */

void task(){
        ll n; cin >> n;
        std::vector<ll> a(n);

        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        ll low = 0, hi = n;
        ll pivot_point = -1; // -1, if nor found
        while(low < hi){
            ll mid  = (low+hi+1)/2;
            if(a[mid] < a[mid-1]){
                pivot_point = mid - 1;
                break;
            }
            else if(a[mid] > a[mid+1]){
                pivot_point = mid;
                break;
            }
            else if(a[n-1]<=a[mid]){ // right unsorted 
                low = mid + 1;
            }
            else hi = mid - 1; // left unsorted
        }

        cout << pivot_point << endl; // pivot point
        if(pivot_point !=-1)cout << a[pivot_point] << endl; // pivot element
}

int main(){
        
#ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif

        int T = 1; cin >> T;
        for(int __ = 1; __ <= T; __++){
            //cout <<"Case "<<__<<": ";
            task();
        }


/*array size ?
 *n==1 ?
 *different approach ?
*/        
return 0;
}
