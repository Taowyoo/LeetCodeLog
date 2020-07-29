// Approach 1: using the kps array from KMP algorithm
// Time: O(n)
// Memory: O(n)
class Solution {
public:
    string longestPrefix(string& s) {
        int N = s.length();
        if(s.length()==0)
            return "";

        //lps dp array
        vector<int> dp = {0}; 
        
        //create lps array
        int i=0;
        for(int j=1; j< N; j++){
            while(i && s[i] != s[j]){
                i = dp[i-1];
            }
            i += s[i]==s[j];
            dp.push_back(i);
        }
        return s.substr(0,dp[N-1]);
    }
};

/*
Approach 2: Incremental Hash
Compute hashes for increasing prefix and suffix, reusing the previously computed hashes. This is similar to the Karp–Rabin algorithm.

For the string of i size, the hash is: s[0] * 26 ^ (i - 1) + s[1] * 26 ^ (i -2) + ... + s[i - 2] * 26 + s[i - 1].

For the prefix hash, we will multiply the previous value by 26 and add a new letter.
For the suffix hash, we add a new letter multiplied by 26 ^ (i - 1).
Note that we need to use some large prime as a modulo to avoid overflow errors, e.g. 10 ^ 9 + 7.
Time: O(n)
Memory: O(1)
*/
string longestPrefix(string &s) {
    long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
        int first = s[i] - 'a', last = s[j] - 'a';
        h1 = (h1 * 26 + first) % mod;
        h2 = (h2 + mul * last) % mod;
        mul = mul * 26 % mod;
        if (h1 == h2)
            len = i + 1;
    }
    return s.substr(0, len);
}

/*
Appendix A2: Collision-Aware Incremental Hash
This is little tricky to implement efficiently. If you check the string for every matching hash, it will be inefficient for repeated patterns. If you only store the largest size, like in the incremental hash solution above, what do you do if suffix and preffx of that size do not match?

We can store all sizes where we have a potential match, but that would require extra memory. We can also try to compute the hash backwards, but you will need to compute the inverse modulo.

Update: see the decremental hash solution in the following appendix.

A simpler idea, which did not occur to me initially, is to compare the string every time you find a matching hash, but only do it for characters we haven't checked before. That way, we can handle repeating patterns efficiently.
*/
string longestPrefix(string &s) {
    long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
        int first = s[i] - 'a', last = s[j] - 'a';
        h1 = (h1 * 26 + first) % mod;
        h2 = (h2 + mul * last) % mod;
        mul = mul * 26 % mod;
        if (h1 == h2) {
            if (s.compare(0, i + 1 - len, s, j, s.size() - j - len) == 0 &&
               s.compare(len, i + 1 - len, s, j + len, s.size() - j - len) == 0)
                len = i + 1;
        }
    }
    return s.substr(0, len);
}
/*
Appendix B: Decremental Hash
The problem with the incremental hash that we do not know if a larger happy prefix exists, and re-checking the string for collisions is expensive (O(n * n) for string with repeating pattern).

What if we compute the hash for the entire string, and then decrement it for suffix and prefix? This way, the first match we find will correspond to the largest happy prefix.

Beware: Inverse Modulo
The formula to compute decremental hash is the reverse of the incremental hash. However, there is no division in the modular arithmetic; instead, we need to multiply by inverse modulo for that number with respect to the modulus (10 ^ 9 + 7 in our case).

Inverse modulo for 26 with respect to 10 ^ 9 + 7 is 576923081. Search online for more information on inverse modulo and extended Euclidian algorithm to compute it.
*/
string longestPrefix(string &s) {
    long h = 0, mod = 1000000007, mul = 1, inverseMod26 = 576923081;
    for (int i = 0, j = s.length() - 1; j >= 0; ++i, --j) {
        h = (h * 26 + s[i] - 'a') % mod;
        mul = mul * 26 % mod;
    }
    long h1 = h, h2 = h;
    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
        mul = mul * inverseMod26 % mod;
        h1 = (h1 - (s[j] - 'a')) * inverseMod26 % mod;
        h2 = (mod + h2 - mul * (s[i] - 'a') % mod) % mod;
        if (h1 == h2) {
            if (s.compare(0, j, s, i + 1, s.size() - i - 1) == 0)
                return s.substr(0, j);
        }
    }
    return "";
}
