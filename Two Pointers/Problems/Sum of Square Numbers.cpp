//https://leetcode.com/problems/sum-of-square-numbers/
class Solution {
public:
    long long square(long long n){
        return (long long)(n*n);
    }
    bool judgeSquareSum(int c) {
        int startPos = 0, endPos = 46341;
        while(startPos<=endPos){
            if(square(startPos) + square(endPos) < c)startPos++;
            else if(square(startPos) + square(endPos) > c)endPos--;
            else return true;
        }
        return false;
    }
};
