class Solution {
public:
    double myPow(double x, int n) {
        // exclude special cases
        if(x == 1) return 1;
        if(x == -1) return n&1 ? -1 : 1;
        if(n == 0) return 1;
        // recursively compute pow and reuse each myPow(x, n/2) at same time
        if(n == 1) return x;
        if(n == -1) return 1/x;
        double result = 0;
        double tmp = myPow(x, n/2);
        if(n&1 != 0)
        {
            result = (n>0 ? x : 1/x) * tmp * tmp;
        }
        else
        {
            result = tmp * tmp;
        }
        return result;
    }
};