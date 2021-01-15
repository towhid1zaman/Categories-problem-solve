
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
const int maxn = 200005;
const int mod = 1000000007;
/*
given an array A of length N.
print all possible subsequence
possible subsequence is 2^N
*/
void subsequence(std::vector<int>a, int index, std::vector<int> sub){
    if(index == a.size()){
        for(int x:sub){
            cout << x <<' ';
        }
        cout << endl;
    }
    else{
        //dont take
        subsequence(a, index+1, sub);
        //take
        sub.push_back(a[index]);
        subsequence(a,index+1, sub);
    }
}

// print subsequence sum
void subsequence_sum(std::vector<int>a,int index, int sum){
    if(index == a.size()){
        cout << sum << endl;
    }
    else{
        // don't take
        subsequence_sum(a, index+1, sum);
        // take
        subsequence_sum(a, index+1, sum+a[index]);
    }
}

//print subsequence with sum
void subsequence_and_sum(std::vector<int>a, int index, std::vector<int>sub){
    if(index == a.size()){
        int sum = 0;
        for(int x:sub){
            sum+=x;
            cout << x <<' ';
        }
        cout << endl <<"sum "<< sum << endl;
    }
    else{
        // don't take
        subsequence_and_sum(a,index+1, sub);
        //take
        sub.push_back(a[index]);
        subsequence_and_sum(a, index+1, sub);
    }
}
void task(){
    int n; cin >> n;
    std::vector<int>a(n);
    for(int i = 0;i<n; i++){
        cin >> a[i];
    }
    int sum = 0;
    //subsequence(a,0,std::vector<int>());
    //subsequence_sum(a,0,sum);
    subsequence_and_sum(a, 0, std::vector<int>());
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef OJ
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
