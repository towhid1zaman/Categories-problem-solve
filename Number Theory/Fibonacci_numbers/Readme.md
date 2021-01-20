
- The Fibonacci numbers are the numbers in the following integer sequence.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..

- In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation 
Fn = Fn-1 + Fn-2

- With base values, 
F0 = 0 and F1 = 1.

* Using Fn = Fn-1 + Fn-2 formula, this will take O(n) time to calculate nth fibonacci number.
* Optimized:
We will be using the following recursion-

If n is even then k=n/2:

F(n)=[2×F(k−1)+F(k)]×F(k)

If n is odd then k=(n+1)/2:

F(n)=F(k)×F(k)+F(k−1)×F(k−1)


This will calculate the fibonacci number in O(logn). Remember to store the values in a map.
