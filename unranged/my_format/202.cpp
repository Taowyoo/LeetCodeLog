// my solution
// Use a hash set to store numbers which has appeared and use hash set to check whether there is a cycle
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> store;
        int next = n;
        int last = n;
        while(!store.count(next)){
            store.emplace(next);
            next = 0;
            while(last){
                int n = last % 10;
                next += n * n;
                last /= 10;
            }
            if(next == 1) return true;
            last = next;
        }
        return false;
    }
};

// Space O(1) solution
// use ideal of Floyd Cycle detection algorithm
class Solution {
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1) return true;
        } while(slow != fast);
        return false;
    }
    int digitSquareSum(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

};