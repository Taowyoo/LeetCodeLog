// DP
// Time: O(n^2)
// Space: O(n^2)
// Explaination:
// state transform:
// dp[i,j] = s[i] == s[j] && dp[i + 1][j - 1]
// dp[i,i+1] = true if s[i] == s[i+1]
// base case:
// dp[i,i] = true
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        
        int n = s.size();
        int maxStart = 0;
        int maxLength = 1;
        vector<vector<bool>> state(n,vector<bool>(n,false));
        // Base cases.
        for (int i = 0; i < n; i++) { 
            state[i][i] = true; // dist = 0.
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int dist = 1; i + dist < n; dist++) {
                int j = dist + i;
                state[i][j] = (dist == 1) ? s[i] == s[j] : (s[i] == s[j]) && state[i + 1][j - 1];
                if (state[i][j] && j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    maxStart = i;
                }
            }
        }     

         return s.substr(maxStart,maxLength);
    }
};

// Expand Around Center
// Time: O(n^2)
// Space: O(1)
// Explaination:
// We observe that a palindrome mirrors around its center. 
//   Therefore, a palindrome can be expanded from its center, and there are only 2n - 1 such centers.
// You might be asking why there are 2n - 1 but not nn centers? 
//   The reason is the center of a palindrome can be in between two letters. 
//   Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) return s;
        
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                start = i - (len - 1) / 2;
                maxLen = len;
            }
        }

         return s.substr(start, maxLen);
    }
private:
    int expandAroundCenter(string& s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }
        return R - L - 1;
    }
};