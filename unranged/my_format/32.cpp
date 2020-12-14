// my solution: store vaild parentheses state in a vector then get the max length by check the vector
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() <= 1) return 0;
        stack<int> store;
        vector<int> count(s.size(),0);
        for(int i = 0; i< s.size(); ++i){
            if(s[i] == ')' && !store.empty() && store.top() > 0){
                count[store.top() - 1] = 1;
                count[i] = 1;
                store.pop();
            }
            else{
                if(s[i] == ')')
                    store.push(-(i+1));
                else
                    store.push(i+1);
            }
        }
        int max = 0;
        int cur = 0;
        for(int& i : count){
            if(i){
                ++cur;
                max = cur>max?cur:max;
            }
            else{
                cur = 0;
            }
        }
        return max;
    }
};

// stack solution: use only one stack to check each vaild parenthese swquence and count the max length
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> store;
        store.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s.[i] == '(') {
                store.push(i);
            } else {
                store.pop();
                if (store.empty()) {
                    store.push(i);
                } else {
                    maxans = std::max(maxans, i - store.top());
                }
            }
        }
        return maxans;
    }
};

// DP:
// if s[i] = ')' and s[i−1] = '(', i.e. string looks like ".......()" then:
// dp[i] = dp[i − 2] + 2
// if s[i] = ')' and s[i − 1] = ')', i.e. string looks like ".......))" and if s[i - dp[i - 1] - 1] = '(' then:
// dp[i] = dp[i − 1] + dp[i − dp[i − 1] − 2] + 2
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        vector<int> dp(s.size());
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = std::max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

// Without extra space
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.at(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = std::max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s.at(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = std::max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};