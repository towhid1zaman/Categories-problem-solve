/*
    string template
*/


// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

/*
    //string getline process,
    string  s;
    cin >> ws; 
    /// getline leaves whitespaces where they are if they don't fit in the line
    // cin >> ws will discard those
    getline(cin, s);


*/
///count something from A string
int cnt(string A, char n){
    int res = count(A.begin(), A.end(), 'n');
    return res;
}

///To Lower
string ToLower(string s) {
    for (int i = 0; i < s.size(); ++i) {
        s[i] = tolower(s[i]);
    }
    return s;
}

///To Upper
string ToUpper(string s) {
    for (int i = 0; i < s.size(); ++i) {
        s[i] = toupper(s[i]);
    }
    return s;
}

///Convert int to string
template <typename T>
string to_str(T str)
{
    stringstream stream;
    stream << str;
    return stream.str();
}

///Convert string to int
template <typename T>
int to_int(T num)
{
    int val;
    stringstream stream;
    stream << num;
    stream >> val;
    return val;
}
///sorting string by their length increasing order
bool ff(string s1,string s2){
    return s1.size()<s2.size();
    ///vector<string>s;sort(s.begin(),s.end(),ff)
}

///length of longest uncommon subsequence of the two strings
ll length(string a,string b){
	if(a==b)return -1ll;

	ll ans = max(a.length(),b.length());
return ans;
}

///check 'a' string is subsequence of string 'b' or not
bool subsequence(string a, string b){
    int cnt = 0;
    for(char x: b){
        if(x==a[cnt]){
            cnt++;
        }
        if(cnt==(int)a.size()){
            return true;
        }
    }
    return false;
}

///check all digits of a string distinct or not
bool uniq(string s){
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = i + 1; j < s.length(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

///check wheather a long number is divisible by "x" or not
bool divisible(string s, int x){
    int xx= 0;
    for(int i = 0; i<s.length();i++){
            xx=((xx*10)+(s[i] - '0') )%x;
    }
    if(xx==0)return true;
    else return false;
}


/*
    string input;

    line input,
    using char, char c[100000000];
                      gets(c);
    using string , string s;
                        getline(cin,s,'\n');

*/

///counting word from string

void  wordCount(){
    char s[10000];
    while(gets(s)){
        int cnt = 0;
        int f = 0;
        for(int i = 0; i<strlen(s);i++){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
                f = 1;
            }
            else
            {
                cnt+=f;
                f = 0;
            }
        }
        cout<<cnt<<endl;
    }
}

///count distinct character in given renge l and r, in q query

void distinct_char_in_range(){
   string s;
    int q;
    cin>>s>>q;
    set<int>check[26];
    for(int i = 0; i<s.size();i++){
        check[s[i]-'a'].insert(i);
    }
    while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            int ans = 0;
            for(int i = 0; i<26;i++){
                auto d = check[i].lower_bound(l);
                if(d!=check[i].end() and *d<=r){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
}


int main(){

        distinct_char_in_range();


return 0;
}

