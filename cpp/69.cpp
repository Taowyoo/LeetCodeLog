class Solution {
public:
    int mySqrt(int x) {
        if(x<=0) return 0;
        double xx(x);
        double hi(x),lo(0);
        double res = hi;
        double bias = 0.00001;
        while(abs(res*res - xx) > bias){
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