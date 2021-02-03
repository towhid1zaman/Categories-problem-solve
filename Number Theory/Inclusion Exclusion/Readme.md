suppose we have two set of A peoples like Fish, and B peoples like meats.

then, how many elements they have in total is,

|AUB| = |A| + |B|--------{  | | -> cardinality }


Now, say some peoples are like fish and meats at the same time, so we need to subtract this this people from total result,
that would be,
|AUB| = |A| + |B| - |A ∩ B|


Now if we have 3 sets of peoples A, B, C the result would be,

|A U B U C| = |A| + |B| + |C| - |A ∩ B| - |A ∩ C| - |B ∩ C| + |A ∩ B ∩ C|

again if the sets more than this, the result would be more complicated.

Approach:

we have seen,

1. if there are N sets, the possible subsets are 2^N - 1
2. in every subset, if they odd, then we add with the result and if they even then we subtract from the result( |A| -> odd(summation), |A ∩ B| -> even(subtraction) )

Finally we can do this using bitmask, or manually one by one.

 
