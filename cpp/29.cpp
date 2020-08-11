class Solution {
public:
    int divide(int dividend, int divisor) {
        // corner case
        if(dividend == std::numeric_limits<int>::min() && divisor == -1)
        {
            return std::numeric_limits<int>::max();
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
            
            res+=inc;
            dend-=red;
            
            red+=sor;
            inc++;
        }
        
        // get the sign of the quotient
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        return sign * res;
    }
};