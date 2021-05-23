// https://leetcode.com/problems/divide-two-integers/
// 29. Divide Two Integers

// count solution
// use an accumulating variable to speed up counting
// Time: O(log(n)^2)
// Space: O(1)
class Solution {
public:
    /**
     * @brief self implementation of divide (integer division)
     * 
     * @param dividend number to be divided
     * @param divisor number use to be divide
     * @return int division result
     */
    int divide(int dividend, int divisor) {
        // corner case
        if(dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        
        // ...Actual calculation of not corner cases...
        
        // use unsigned int to calculate absolute value of quotient. Later, sign will be calculated.
        unsigned int dend = std::abs(dividend); 
        unsigned int sor = std::abs(divisor);
        
        // used for fast forwarding the calculation. 'red' is used to reduce the divident at faster rate in next iteration. 'inc' is increased in sync with 'red' to get to the quotient faster. 
        unsigned int red = std::abs(divisor);
        unsigned int inc = 1;


        unsigned int res = 0;
        while(dend >= sor)
        {
            // in case the 'red' becomes bigger than dend. start over.
            if(red > dend)
            {
                red = sor;
                inc = 1;
            }
            
            res += inc;  // update result
            dend -= red;  // reduce counted part
            
            // double both reduction and count number in order to speed up
            red += red;
            inc += inc;
        }
        
        // get the sign of the quotient
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        return sign * res;
    }
};

// binary search solution
// using power of 2 as a kind of binary search
// we can use bit shift to perform '*2' operation
// Time: O(log(n))
// Space: O(1)
class Solution {
    constexpr static int HALF_INT_MIN = INT_MIN / 2;
public:
    /**
     * @brief self implementation of divide (integer division)
     * 
     * @param dividend number to be divided
     * @param divisor number use to be divide
     * @return int division result
     */
    int divide(int dividend, int divisor){
        // consider corner case that is special with the limitation of int
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // use long to avoid other corner case, and convert both number to positive number to simplify computation
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        // get the sign of result by using XOR, when both same answer is positive otherwise negative
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        // loop until divisor bigger than dividend
        while (dvd >= dvs) {
            // the initial conditions are:
            // using a temp varaible to record current divisor*m
            // m is multiplier of divisor
            long temp = dvs, m = 1;
            // get the biggest divisor*m that <= dividend
            // also the corresponding number m
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            // reduce current temp: reduce m number of divisor we have accumulated
            dvd -= temp;
            // correspondingly, add m to ans, we got m number of divisor in dividend so far
            ans += m;
            // continue loop
        }
        return sign * ans;  // return answer with corret sigh
    }
};
