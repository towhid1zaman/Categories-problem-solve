#include <bits/stdc++.h>
#define S 5003
using namespace std;

vector <int> Fib[S], addition;

void Fib_Number(){
    Fib[0].push_back(0);
    Fib[1].push_back(1);
    for(int i = 2; i < S; i++){
        int sz1 = Fib[i-2].size()-1;
        int sz2 = Fib[i-1].size()-1;
        int tmp, ad, c = 0;
        while(sz1 >= 0 && sz2 >= 0){
            ad = c+Fib[i-2][sz1]+Fib[i-1][sz2];
            if(ad > 9){
                c = ad/10;
                ad %= 10;
            }
            else c = 0;
            addition.push_back(ad);
            sz1--, sz2--;
        }
        if(sz1 >= 0){
            while(sz1 >= 0){
                ad = c+Fib[i-2][sz1];
                if(ad > 9){
                    c = ad/10;
                    ad %= 10;
                }
                else c = 0;
                addition.push_back(ad);
                sz1--;
            }
        }
        if(sz2 >= 0){
            while(sz2 >= 0){
                ad = c+Fib[i-1][sz2];
                if(ad > 9){
                    c = ad/10;
                    ad %= 10;
                }
                else c = 0;
                addition.push_back(ad);
                sz2--;
            }
        }
        if(c)addition.push_back(c);
        int sz = addition.size();
        for(int z = sz-1; z >= 0; z--)Fib[i].push_back(addition[z]);
        addition.clear();
    }
}

int main(){
    Fib_Number();
    int n;
    while(cin >> n){
        int sz = Fib[n].size();
        cout << "The Fibonacci number for " << n << " is ";
        for(int i = 0; i < sz; i++)cout << Fib[n][i];
        puts("");
    }
    return 0;
}
