/**
 * my solution
 * 1. create a reversed string of string s called rs
 * 2. use KMP to get length of first longest Palindrome in string s
 * 
 * time: O(n)
 * memory: O(n)
 */
class Solution {
public:
    string shortestPalindrome(string s) {
        if(s == "") return s;
        // get a reversed s
        string rs(s);
        reverse(rev.begin(), rev.end());
        // use KMP to get sub palindrome length
        int n = myKMP(rs,s);
        return rs + s.substr(n);
    }
private:
    int myKMP(string& rs, string& s){
        int N = s.size();
        vector<int> LPS = getLPS(s);
        int i = 0;  // index of rs
        int j = 0;  // index of s
        while(i < N){
            while(j < N){
                if(rs[i] == s[j]){
                    ++i;
                    ++j;
                    if(i == N) return j;
                }
                else if(j > 0){
                    j = LPS[j - 1];
                }
                else{
                    ++i;
                }
            }
        }
        return 1;
    }
    vector<int> getLPS(string& s){
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};

// KMP solution with only LPS
// combine original string and reversed string , and use LPS array of such combined string to fine the sub Palindrome

string shortestPalindrome(string s)
{
    int n = s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    string s_new = s + "#" + rev;
    int n_new = s_new.size();
    vector<int> f(n_new, 0);
    for (int i = 1; i < n_new; i++) {
        int t = f[i - 1];
        while (t > 0 && s_new[i] != s_new[t])
            t = f[t - 1];
        if (s_new[i] == s_new[t])
            ++t;
        f[i] = t;
    }
    return rev.substr(0, n - f[n_new - 1]) + s;
}

