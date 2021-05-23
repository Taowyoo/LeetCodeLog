// https://leetcode.com/problems/valid-palindrome/

// My solution
// Time: O(n)
// Space: O(1)
// Explanation:
// 1. Clear all not alphanumeric characters
// 2. check whether the string is a palindrome
class Solution {
private:
    /**
     * @brief clear all not alphanumeric characters
     * and transform all characters to lower case
     * 
     * @param s Pending input string
     */
    void clear(string& s){
        int j = 0;
        for(int i = 0; i<s.size();++i){
            // ignore all not alphanumeric characters
            if(s[i] >= 'a' && s[i] <='z' || s[i] >= '0' && s[i] <='9'){
                s[j++] = s[i];
            }
            // transform all characters to lower case
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[j++] = s[i] - 'A' + 'a';
            }
        }
        s.resize(j);
    }
    /**
     * @brief use two pointer to check whether given string is a palindrome
     * 
     * @param s Input string
     * @return true Given string is a palindrome
     * @return false Given string is not a palindrome
     */
    bool isPa(string& s){
        int i = 0;
        int j = s.size() - 1;
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    /**
     * @brief check whether given string is a palindrome
     * 
     * @param s Input string
     * @return true Given string is a palindrome
     * @return false Given string is not a palindrome
     */
    bool isPalindrome(string s) {
        // firstly, clear all not alphanumeric characters
        // and transform all characters to lower case
        clear(s);
        // then use two pointer to check whether it's a palindrome
        return isPa(s);
    }
};

// A better and clear solution
// two pointer
// Time: O(n)
// Space: O(1)
/**
 * @brief check whether given string is a palindrome
 * 
 * @param s Input string
 * @return true Given string is a palindrome
 * @return false Given string is not a palindrome
 */
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }
    return true;
}