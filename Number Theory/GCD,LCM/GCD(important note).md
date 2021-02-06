From basic properties of GCD we know that GCD(x,y)=GCD(x−y,y). The same applies for multiple arguments: GCD(x,y,z,…)=GCD(x−y,y,z,…). 

Let's use this for GCD(a1+bj,…,an+bj) and subtract a1+bj from all other arguments: GCD(a1+bj,…,an+bj)=GCD(a1+bj,a2−a1,…,an−a1).

If we find G=GCD(a2−a1,…,an−a1), then any answer can be found as GCD(a1+bj,G). 

Note that we have to assume that GCD of an empty set is 0, and GCD(x,0)=x for any x, since 0 is the only number divisible by any other number.

problem:https://codeforces.com/contest/1459/problem/C
