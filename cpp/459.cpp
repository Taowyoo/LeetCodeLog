// my solution
// use LPS array to check whether the string can be constructed by taking a substring of it
// time: O(n)
// memory: O(n) 
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int N = s.size();
        if(N == 1) return false;
        int num = kmpProcess(s);
        if(num >= N/2){
            return N % (N-num) ? false:true;
        }
        return false;
    }
private:
    int kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps.back();
    }
};
// Other's kmp solution
// First, we build the KMP table.
//   Roughly speaking, dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i.
//   Therefore, if a string repeats a length 5 substring 4 times, then the last entry would be of value 15.
//   To check if the string is repeating itself, we just need the last entry to be non-zero and str.size() to divide (str.size()-last entry).
 bool repeatedSubstringPattern(string str) {
    int i = 1, j = 0, n = str.size();
    vector<int> dp(n+1,0);
    while( i < str.size() ){
        if( str[i] == str[j] ) dp[++i]=++j;
        else if( j == 0 ) i++;
        else j = dp[j];
    }
    return dp[n]&&dp[n]%(n-dp[n])==0;
}