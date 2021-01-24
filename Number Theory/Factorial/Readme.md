
* Factorial is multiplication of a number, from 1 to n
* n factorial written as, n!
* n! = n-1 * n-2 * n-3 * ...... * 1

* Digit of N!
* we know,

log10(100)=2

log10(150)=2.17609125906

log10(500)=2.69897000434

log10(999)=2.99956548823

So basically log(x) + 1 is number of digits of x
So, How to calculate x!

can written as, log(1 * 2 * 3) = log(1) + log(2) log(3)...

so x! = 1 * 2 * 3 * .... * x = log(1) + log(2) + log(3) + ....

this log is 10 base, so if we use c++ , then we have to write, log10(x)


Now, what if we have to change our base, like in 2 base sytem how many digits of 5!
then the answer will be change.

So, basically we have to change our base, 10 to given base, 

we now that,

logxy = logxz * logzy

⟹logzy=logxy * logxz

∴logbn=log10n/log10b

