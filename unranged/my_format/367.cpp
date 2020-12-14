class Solution {
public:
    bool isPerfectSquare(int num) {
        long hi(num),lo(0);
        long res = hi;
        while(hi > lo){
            if(res*res > num) hi =res;
            else lo = res+1;
            res = (hi+lo) >> 1;
        }
        res = lo - 1;
        return res*res == long(num);
    }
};