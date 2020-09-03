
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;


/*Print all subsequence of a string
 *We can do it by bitmasking
 *let s = ABC
 *int n = s.size();
 *ABC = s
 *012 = position
 *
 *So how many combination we can make, its 2^n - 1 (one is empty subsequence)
 *combinations:
 *ABC
 *000 (empty subsequences)
 *001 = C
 *010 = B
 *100 = A
 *110 = AB
 *111 = ABC
 *101 = AC
 *011 = BC
 *
 *see, only those bit is set, only we can take this char
 *
 *
 *
 *

 
 */


bool comp(string s, string t){
    return s.size()<t.size();
}
void task(){
    string s; cin >> s;
    int n = s.size();
    int totSub = (1<<n)-1;
    std::vector<string>subsequences;
    for(int i = 1; i<=totSub; i++){
        int N = i;
        int j = 0;
        string sub = "";
        while(N){
            if(N&1)sub+=s[j];
            j++;
            N>>=1;
        }
        subsequences.push_back(sub);
    }
    cout << subsequences.size() << endl;
    sort(subsequences.begin(), subsequences.end(), comp);
    for(string  s:subsequences){
        cout << s << endl;
    }
}

int main(){
        
        #ifdef OJ
        freopen("inputf.in", "r", stdin);
        freopen("outputf.in", "w", stdout);
        #endif

        int T = 1; cin >> T;
        while(T--){
            task();
        }
        
        
return 0;
}


