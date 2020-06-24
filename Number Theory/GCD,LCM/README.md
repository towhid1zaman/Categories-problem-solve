# GCD/LCM

**GCD:**

GCD : Greatest Common Divisor, its also called, HCF : Highest Common Factor.\
Suppose that, Ans = GCD(A,B), This Ans is the Highest or Greatest Number that can divide Both A and B.

Let A = 8 , and B = 20\
Now Find Out Divisor of This two Numbers.\
8 = 1,2,4,8 \
20 = 1,2,4,5,10,20

So we see,\
1 can can devide both of them.\
2 can devide both of them\
4 can devide both of them\
We already know that , we have choose greatest Number that can devide both of them, that is 4. So our GCD/HCF is 4.

Now, How Can We calculate it ?

**Bruteforce:**\
 for i=1....Min(A,B)\
  choose Biggest i that can Devide Both Of them.
Complexity:O(min(A,B))

**Euclid's Division Algorithm:**\
We can write any number as A = B * q + r\
where q=Quotient(ভাগফল), r=Remainder(ভাগশেষ)

Lets,\
7)25(3\
  21 \
 ----\
  4
  
So, we can write it as, 25=7*3+4

this Remainder(r) called Euclid Division Lemma, It is use to calculate GCD.\
GCD(A,B) = GCD(B, A%B), Recursively.The Base case is B=0, means GCD(A,0)=A, A is the GCD.

Now How it Works,\
Let, A = 12, B = 20.\
12)20(1\
   12\
   ----\
   8)12(1\
      8\
     ---\
      4)8(2\
        8\
       ---\
        0)4(
        
Here, B=0, and A=4. We see, After Every Division, we choose Remainder As B, and we did it untill it become 0.

so it,\
------\
|0,  4|we found base case 0, so it return 4,\
|-----|\
|4,  8|return 4\
|-----|\
|8, 12|return 4\
|-----|\
|12,20|return 4

so, finally the GCD we found is 4. Note, if (A<B) or (A>B) it doesn't matter. it automatically swaped.

Complexity:O(log(max(A,B)))


**LCM:**

Now, LCM means Least Common Multiple, it simply gcd*lcm=(a*b)
