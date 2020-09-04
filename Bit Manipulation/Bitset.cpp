
// </> : towhid1zaman

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#include "bits/stdc++.h"
using namespace std;

typedef long long ll;


/*bitset<size>name;
 *kind of array, and start indexed 0 , from right side
 *store binary number
 *
 *6543210 (position)
 *1010101 (binary numbers)
 *
 */

//simple assignment
void assign(){
	bitset<3>a;
	a[0] = 1;
	a[1] = 0;
	a[2] = 0;
	cout << a << endl; //001
}

// integer to binary and vice-versa
void itob(){
	//to_binary
	bitset<8>a(12);
	cout << a << endl; //00001100

	//to_integer
	int n = (int)a.to_ulong();
	cout << n << endl; //12

	//from string 
	string s = "00001100";
	bitset<8>b(s);
	int N = (int)b.to_ulong();
	cout << N << endl; //12

	//count number of ones

	cout << b.count() << endl; //2
}


// string operations
void string_operation(){
	//to_int
	string s = "00001100";
	bitset<8>b(s);
	int N = (int)b.to_ulong();
	cout << N << endl; //12

	string t = "101010010101";
	bitset<2>A;
	bitset<4>B;

	// if i want to take first n digit from string

	stringstream stream(t);
	stream >> A;
	cout << A << endl; //10

	stream >> B;
	cout << B << endl; //1010

	//
}

// basic operations [&&, ||, <<, >>]

void basic_operations(){
	bitset<6>a(string("101011"));
	bitset<6>b(string("110101"));

	cout << (a & b) << endl; // and operator = 100001 (both set, then 1, else 0)
	cout << (a | b) << endl; //or operator = 111111 (if any set, then 1)
	cout << (a ^ b) << endl; //xor operator = 011110 (if same, then 0, else 1)
	cout << (~a) <<endl; // flip all the bit, 0-1, 1-0 = 010100

	cout << (a << 1) << endl; // left shit, cutting i bit, from left and add i 0 from right, 010110
	cout << (b >>1) << endl; //right shit, cutting i bit , from right and add i 0 from left, 011010

}

// check any bit set or not
void setOrNot(){
	bitset<4>a(string("1010"));
	bitset<4>b(string("0000"));
	bitset<4>c(string("1111"));
	if(a.any())cout << "Present" << endl;
	else cout << "Not Present" << endl;

	if(b.any()) cout << "Present" << endl;
	else cout << "Not Present" << endl;

	// check all bit set or not
	cout << a.all() << endl; //false;
	cout << c.all() << endl; //true

}

// Flip bit, 0-1, 1-0
void Flip(){
	string s = "10101";
	bitset<5> a(s);
	cout << a.flip() << endl; //01010

	// flip any perticular indexed, we know bitset indexed strat from right[0 based]

	string t = "01011";
	int n = t.size();
	bitset<5>b(t);
	cout << b.flip(1) << endl; // indexed 1 will be flip, 01001
}

//Set = make all bit 1, and  Reset bit = make all bit 0;

void Set_Reset(){
	string s = "10101";
	bitset<5>a(s);
	cout << a.reset() << endl;//00000

	string t = "10101";
	bitset<5>b(s);
	cout << b.set() << endl;//11111

	// for any perticular indexed a.set(1) or a.reset(1);

}

void task(){
       
       //assign();
       //itob();
	   //basic_operations();
	   //string_operation();
    	//setOrNot();
		//Flip();
		Set_Reset();
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


