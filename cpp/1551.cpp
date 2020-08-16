// my solution
// one pass
// Time : O(n)
class Solution {
public:
    int minOperations(int n) {
        if(n <= 1) return 0;
        int res = 0;
        for(int i = 1; i <= n; i+=2){
            res += n-i;
        }
        return res;
    }
};