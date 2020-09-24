
// </> : towhid1zaman


#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

//integer to binary conversion
string to_binary(int n){
	string s="";
	while(n){
		if(n%2)s+='1';
		else s+='0';
		n=n>>1;
	}
	reverse(s.begin(), s.end());
	return s;
	
	// also we can use bitset
	//cout << bitset<64>(n) << endl;
}

/*
 *Given a sequence of number , every number is appeared twice,
 *only one number is present one time, find this unique number
 */
int unique_number(std::vector<int>&v){
	int n = v.size();
	int ans = 0;
	for(int i = 0; i<n; i++){
		ans^=v[i];
	}
	return ans;
}

/*
 *given a number , return its 2's complement [ if n = 5, return -5 in binary form]
 *
 * let, x = 5;
 * 5 = 00000101(binary)
 *
 * 	   11111010(flip all bits)
 *   		 +1(add 1)
 *----------------------
 *	   11111011 (binary representation of -5)
 *
 */

// swap two number using XOR
void swap(int a, int b){
	cout <<"Before swaping "<<a<<' '<<b<<endl;
	a = a^b;
	b = b^a;
	cout << "after swaping ";
	cout << (a^b) << ' '<<b << endl;
}

/*count number of set bit(1) in binary form of a number
 *__builtin_popcount = int
 *__builtin_popcountl = long int
 *__builtin_popcountll = long long
*/

//Counts the leading number of zeros of the integer(long/long long).
/*
Ex- int x=16;       // 00000000 00000000 00000000 00010000 (32 bits)
      cout<<__builtin_clz(x)<<endl;   //returns 27.
 */
ll LZ(ll x){
	return __builtin_clz(x);
}

int CountSet(int n){
	//return __builtin_popcount(n);
	int ans = 0;
	while(n>0){
		ans+=(n&1);
		n>>=1;
	}
	return ans;
}

/* Count different set bit
 *given two numbers, count its different bit in every position of their binary form
 * let, a = 11, b = 15
 *	a=1011
 *	b=1111
 * here differnt position is 1, so count is 1
 */
 int different_bit(int a, int b){
 	int c = a^b;
 	return __builtin_popcount(c);
 }

 /*Remove Last SetBit of a number 
  *Suppose, given a number 13 = 1101, after removing last bit,
  *it will be , => 1100
  */
int Remove_lastBit(int n){
	int ans = n&(n-1);
	return ans;
}

/*Check ith bit is set or not
 *Given a number, check the ith bit is 1 or not.
 * means ith position of binary representation is 1 or 0
 * 13 = 1101(3rd,2nd,1st,0th position)
 */
bool ithBit_SetOrNot(int N, int i){
	if( N & (1 << i) )
        return true;
    else
        return false;
}

/*change ith bit of a number
 *let n = 13 = 1101
 *			 = 0010(mask of 1th bit (1<<1))
 *-------------------------------------
 *		(xor)=1111 (result , after change 1st bit)
 */
 int changeithBit(int n, int i){
 	return (n^(1<<i));
 }

 /* Given a number , check it is power of 2 or not
  * let n = 8, it is a power of two number, 
  * we can write, 8 = 2^3
  */

 bool PowerOfTwo(int n){
 	return (n && !(n&(n-1)));
 }

void task(){
	int n; cin >> n;
	int i; cin >> i;
	cout << ithBit_SetOrNot(n,i) << endl;
	cout << changeithBit(n,i) << endl;
	cout << PowerOfTwo(n)<<endl;
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


