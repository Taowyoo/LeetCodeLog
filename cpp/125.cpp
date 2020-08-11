// my solution
// Time: O(n)
// Space: O(1)
// Explaination:
// 1. Clear all not alphanumeric characters
// 2. check whether the string is a palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        clear(s);
        return isPa(s);
    }
private:
    void clear(string& s){
        int j = 0;
        for(int i = 0; i<s.size();++i){
            if(s[i] >= 'a' && s[i] <='z' || s[i] >= '0' && s[i] <='9'){
                s[j++] = s[i];
            }else if(s[i] >= 'A' && s[i] <= 'Z'){
                s[j++] = s[i] - 'A' + 'a';
            }
        }
        s.resize(j);
    }
    bool isPa(string& s){
        int i = 0;
        int j = s.size() - 1;
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};

// a better and clear solution
// two pointer
// Time: O(n)
// Space: O(1)
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
        while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
        while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
        if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
    }
    
    return true;
}