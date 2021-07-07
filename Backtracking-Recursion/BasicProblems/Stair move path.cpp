/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

/*
    Given a stair of size n, print all possible path to
    move from 0 to  nth stair

    Move = 1,2,3,4,5,6 jumps at a time
*/
void print_path(int cur_p, int n, string cur_path,int &tot_path){
    if(cur_p >= n)return;
    if(cur_p == n-1){
        cout << cur_path << endl;
        tot_path ++;
        return;
    }

    for(int i =  1; i <= 6; i++){
        print_path(cur_p+i, n, cur_path + to_string(i), tot_path);
    }

}
void task(){
    int n; cin >> n;
    int tot_path = 0;
    print_path(0,n,"", tot_path);
    cout << "TOTOL PATH "<<tot_path << endl;
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
