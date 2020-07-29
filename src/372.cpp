class Solution {
public:
    int getPow(int x,int num){
        int res = 1;
        for(int i = 0; i < num; ++i){
            res *= x;
            res %= 1337;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        a %= 1337;
        int val = 1;
        int res;
        for(int i : b){
            val *= getPow(a,i);
            val %= 1337;
            res = val;
            val = getPow(val,10);
        }
        return res;
    }
    

};