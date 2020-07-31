We want to find m1 and m2 that satisfy the equation  n1 * m1 + n2 * m2 = n, and give us the minimum cost where cost = c1 * m1 + c2 * m2 .
Using extended Euclid to find gcd(n1,n2) and get m1`,m2` where n1 * m1` + n2 * m2` = gcd(n1,n2)
to get m1 and m2 multiply both sides by n/gcd m1`=m1`*n/gcd , m2`=m2`*n/gcd.
Now m1 = m1 + n2 / g * t  , m2 = m2 –  n1 / g * t   any integer t satisfy the desired equation, but we want to minimize the cost  c = c1 * m1 + c2 * m2 = c1 * ( m1 + n2 / g * t )  +   c2 * ( m2 – n1 /g * t) = c1*m1 +c2*m2 + t * (c1* n2/g – c2 *n1/g).
Since c1*m1 +c2*m2  is constant we want to minimize  t * (c1* n2/g – c2 *n1/g)
How to get t ?
As we mention above m1 = m1 + n2 / g * t  , m2 = m2 –  n1 / g * t , m1 && m2 >=0
So m1 + n2 / g * t >=0 ,  n2 / g * t >= – m1 ,  t >= – m1 *g / n2
Also m2 –  n1 / g * t>=0  ,  – n1 / g * t >= – m2 , t <= m2 * g / n1
so ceil(-m1*g/n2) <= t <= floor(m2*g/n1),
Now  just check the two boundaries, and choose the one that give you the cheaper cost.
