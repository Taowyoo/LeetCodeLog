// my solution ver.1
// time: O(n)
// memory: O(1)
class Solution {
public:
    int numSub(string s) {
        int res = 0;
        int mod = 1000000007;
        int num = 0;
        for(char ch : s){
            if(ch == '0'){
                res += getSubNum(num);
                res %= mod;
                num = 0;
            }
            else{
                ++num;
            }
        }
        res += getSubNum(num);
        res %= mod;
        return res;
    }
    int getSubNum(long long n){
        long long res = ((1 + n) * n) >> 1;
        return res % 1000000007;
    }
};

// my solution ver.2
// time: O(n)
// memory: O(1)
class Solution {
public:
    int numSub(string s) {
        int res = 0;
        int mod = 1000000007;
        int num = 0;
        for(char ch : s){
            if(ch == '1'){
                ++num; 
                res += num;
                res %= mod;
            }
            else{
                num = 0;
            }
        }
        return res;
    }

};