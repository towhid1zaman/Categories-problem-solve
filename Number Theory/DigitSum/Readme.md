- Digit sum properties:
- The digit sum of a number, say 152, is just the sum of the digits, 1+5+2=8. If the sum of the digits is greater than nine(9) then the process is repeated. For example, the sum of the digits for 786 is 7+8+6=21 and the sum of the digits for 21 is 3 so the digit sum of 786 is 3.
- * The most famous property of digit sums is that the digit sum of all multiples of 9 is 9.
For examples, DigitSum(18)=9, DigitSum(27)=9, DigitSum(99)=9, etc.
- * DigitSum(a+b) = DigitSum(DigitSum(a)+DigitSum(b))
Example, DigitSum(786+152) = DigitSum(938) = 2
DigitSum(786) + DigitSum(152) = DigitSum(3 + 8) = 2
- * DigitSum(a-b) = DigitSum(DigitSum(a)-DigitSum(b))
Example, DigitSum(962-151) = DigitSum(811) = 1
DigitSum(962) - DigitSum(151) = DigitSum(8-7) = 1 [ a > b ]
- * DigitSum(a*b) = DigitSum(DigitSum(a)*DigitSum(b))
Example: DigitSum(35*16) = DigitSum(560) = 2
DigitSum(35)*DigitSum(16) = DigitSum(8*7) = DigitSum(56) = 2
- * Division by single digit numbers other than multiples of 3 is equivalent to multiplication by a specific digit for that divisor. For example, division by 2 is equivalent to multiplication by 5. Thus DigitSum(32/2) = DigitSum(32*5) = DigitSum(160) = 7. which is the same as DigitSum(16). Division by 4 is equivalent to multiplication by 7 so DigitSum(20/4) = DigitSum(20*7) = DigitSum(140) = 5, which is correct.
The rule is DigitSum(a/b) = DigitSum(DigitSum(a)*Equivalent(DigitSum(b))) providing that DigitSum(b) is not a multiple of 3.
