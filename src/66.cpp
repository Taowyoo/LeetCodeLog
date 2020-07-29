// my solution
// time: O(n)
// memory: O(n)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add = 1;
        int base = 10;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it){
            if(add == 0) break;
            add += *it;
            *it = add % base;
            add /= base;
        }
        if(add != 0) digits.insert(digits.begin(),add);
        return digits;
    }
};