#include "bits/stdc++.h"
using namespace std;

struct FenwickTree{
    int N;
    vector<int> tree;
 
    void build(int n){
        N = n;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int val){
        while (idx <= N)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    void updateMax(int idx, int val){
        while (idx <= N)
        {
            tree[idx] = max(tree[idx], val);
            idx += idx & -idx;
        }
    }
     //mainly Query
    int pref(int idx){
        int ans = 0;
        while (idx > 0){
            ans += tree[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
     //range sum
    int rsum(int l, int r){
        return pref(r) - pref(l - 1);
    }

    int prefMax(int idx){
        int ans = -2e9;
        while (idx > 0){
            ans = max(ans, tree[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }

    int search(int val){
        int curSum=0,pos=0;
        for(int i = log2(N)+1;i>=0;i--){
            if(pos + (1<<i) < N && curSum + tree[ pos+(1<<i) ] < val){
                curSum += tree[pos+(1<<i)];
                pos += (1<<i);
            }
        }
        return pos+1;
    }
};
void task(){
    int n; cin >> n;
    FenwickTree bit;
    bit.build(n);
    std::vector<int>a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        bit.update(i, a[i]);
    }
    
    cout << bit.search(66) << endl;

    bit.updateMax(3, 10);
    for(int i = 1; i<=n; i++)cout << bit.pref(i)<<' ';cout << endl;
    cout << bit.pref(3) << endl;

}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}

/*
10
1 2 33 4 66 6 7 8 9 10
*/
