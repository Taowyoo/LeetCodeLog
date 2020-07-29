// my solution
// Time complexity : O(sqrt(n))
// Space: O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 0) {
            return false;
        }
        int sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i;
                if (i * i != num) {
                    sum += num / i;
                }

            }
        }
        return sum - num == num;
    }
};

// Approach #4 Euclid-Euler Theorem [Accepted]
// Euclid proved that (2^p − 1)*2^{p−1} is an even perfect number whenever 2^p − 1 is prime, where p is prime
/* JAVA Example
public class Solution {
    public int pn(int p) {
        return (1 << (p - 1)) * ((1 << p) - 1);
    }
    public boolean checkPerfectNumber(int num) {
        int[] primes=new int[]{2,3,5,7,13,17,19,31};
        for (int prime: primes) {
            if (pn(prime) == num)
                return true;
        }
        return false;
    }
}
*/
// Time: O(log(n))
// Space: O(log(n))
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int perfects[] = {6, 28, 496, 8128, 33550336};
        for(int i = 0; i < 5; ++i){
            if(perfects[i] == num) return true;
        }
        return false;
    }
};