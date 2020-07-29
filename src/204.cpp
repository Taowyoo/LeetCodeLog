// my solution
// Time: O()
class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        int num = 1;
        int upper = sqrt(n);
        vector<bool> record(n,false);
        for(int i = 3; i < n; i += 2){
            if(record[i]) continue;
            else{
                ++num;
                if(i > upper) continue;
                int k = i * i;
                while(k < n){
                    record[k] = true;
                    k += i;
                }
            }
        }
        return num;
    }

};



// Short C++ Sieve of Eratosthenes solution
class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 2; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }

};