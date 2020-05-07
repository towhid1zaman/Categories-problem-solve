
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int LIS(vector<int>v, int n){
    vector<int>temp;
    temp.push_back(v[0]);
    for(int i = 1; i<n; i++){
        if(v[i]>temp.back()){
            temp.push_back(v[i]);
        }
        else{
            auto it = lower_bound(temp.begin(),temp.end(),v[i]) - temp.begin();
            temp[it] = v[i];
        }
    }

    return temp.size();
}

int main(){
        _ios;

        int n; cin >> n;
        vector<int>v(n);
        for(int i = 0; i<n; i++){
            cin >> v[i];
        }

        int ans = LIS(v,n);
        cout<<ans<<endl;

return 0;
}

/*

10
4 5 6 1 2 3 4 7 5 10

6

*/

