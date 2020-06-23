# Properties of Modular arithmetic:

**1. (A+B)%M = (A%M + B%M)%M**

  '%' Means, its gives us a reminder(ভাগশেষ) \
  LET, A = 5, B = 8 , AND M = 3 \
  so result is, \
  (A+B)%M = (13)%3 = 1 \
  Nw, applying rules, \
  (A+B)%M = (A%M + B%M)%M = (5%3 + 8%3)%3 = (2 + 2)%3 = (4)%3 = 1 
  
  **2. (A-B)%M = ((A%M - B%M) + M)%M**
  
  NOW, Question is why we add extra M.\
  Let , A = 12, B = 15, and M = 4\
  (12-15)%4 = (12%4 - 15%4)%4 = (0-3)%4 = -3, So we see, the result is negative , the answer of the % operator cannot be negative.\
  So, thats why we add M\
  (12-15)%4 = (12%4 - 15%4 + 4)%4 = (0 - 3 + 4)%4 = 1
  
  **3. (A*B)%M = (A%M * B%M)%M**
  
  Here we can actually see why we need modular arithmetics, Lets Say A = 10^18 , B = 10^18 and M = mod(1e9 + 7)\
  so, if we multiply A*B that is 10^36 this is not conform with our data types.

  **4. (A/B)%M = (A%M * B^-1 %M)%M**
  
  We see, division property quite different from other property.\
  Here B^-1 its called **multiplicative modulo inverse**
  
  properties of mod inverse\
      a^-1 % m\
    =a^(m-2) % m

  **Note:**
  x%m, if m<x then result always m
