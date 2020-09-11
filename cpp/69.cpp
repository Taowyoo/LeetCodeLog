// https://leetcode.com/problems/sqrtx/
// 69. Sqrt(x)

// my binary search by using double and checking bias
// Time: O(log(x))
// Space: O(1)
class Solution {
public:
    /**
     * @brief get sqrt of number x, result is truncated 
     * 
     * @param x input number
     * @return int the sqrt result which is truncated to a int
     */
    int mySqrt(int x) {
        if(x<=0) return 0;
        double xx(x);
        double hi(x),lo(0);
        double res = hi;
        double bias = 0.00001;
        // by check whether each small enough bias to stop the loop
        while(abs(res*res - xx) > bias){
            // by compare res^2 with x, to check whether it's too big or too small
            if(res*res > xx){
                hi = res;
            }
            else{
                lo = res;
            }
            res = (hi + lo) / 2;
        }
        return int(res);
        
    }
};

// binary search by checking whether reach bigger int sqrt result
class Solution {
public:
    /**
     * @brief get sqrt of number x, result is truncated 
     * 
     * @param x input number
     * @return int the sqrt result which is truncated to a int
     */
    int mySqrt(int x) {
        if(x < 2) return x;
        long lo = 1;
        long hi = x;
        long res= lo + (hi - lo) / 2;
        long last = 1;
        // by checking whether current res is recurring
        // we can determine whether we got the result
        while(last != res && lo < hi){
            
            if(res * res > x) hi = res;
            else lo = res;
            last = res;
            res = lo + (hi - lo) / 2;
        }
        return res;
    }
};

// Recursion + Bit Shifts
class Solution {
public:
    /**
     * @brief get sqrt of number x, result is truncated 
     * 
     * @param x input number
     * @return int the sqrt result which is truncated to a int
     */
    int mySqrt(int x) {
        if (x < 2) return x;
        // use recursion to reach base case above:
        // sqrt(x) = sqrt(x / 4) * 2
        int left = mySqrt(x >> 2) << 1;
        // check for truncation
        int right = left + 1;
        return (long)right * right > x ? left : right;
    }
};