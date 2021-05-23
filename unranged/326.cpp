// my solution
// Time: O(log3(n))
// Memory: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

// Approach 2: Mathematics
// Time: O(?) base on the time complexity of log10()
// Memory: O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        double k = (log10(n) / log10(3));
        return  std::floor(k) == k;
    }
};

// Approach 4: Integer Limitations
// Time: O(1)
// Memory: O(1)
constexpr int MaxPowerOfThree() {
    int n = 3;
    while (n < std::numeric_limits<int>::max() / 3) { 
        n = n * 3;
    }    
    return n;
}

bool isPowerOfThree(int n) {
    constexpr int maxPowerOfThree = MaxPowerOfThree();
    return n > 0 && maxPowerOfThree % n == 0;
}
