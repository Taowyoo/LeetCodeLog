// https://leetcode.com/problems/decode-string/

class Solution {
    /**
     * @brief Get an alphabet string from string stack
     * the function will joint all adjacent alphabet string from the top of stack
     * then return whole string
     * @param stk stack that store characters
     * @return string a full alphabet string
     */
    string getChars(stack<string>& stk){
        string res = "";
        while(!stk.empty() && isalpha(stk.top().front())){
            res = stk.top() + res;
            stk.pop();
        }
        if(!stk.empty() && stk.top().front() == '[') stk.pop();
        return res;
    }

    /**
     * @brief Get a number from string stack
     * the function will joint all adjacent number string from the top of stack
     * then return its int value
     * @param stk stack that store strings
     * @return int 
     */
    int getNum(stack<string>& stk){
        string res = "";
        while(!stk.empty() && isdigit(stk.top().front())){
            res = stk.top() + res;
            stk.pop();
        }
        if(!stk.empty() && stk.top().front() == '[') stk.pop();
        return stoi(res);
    }
public:
    /**
     * @brief decode the input string according to specific format:
     * examples: "3[a]2[bc]" -> "aaabcbc"
     *           "2[abc]3[cd]ef" -> "abcabccdcdcdef"
     * 
     * @param s coded string
     * @return string decoded string
     */
    string decodeString(string s) {
        // use a stack to implement brackets match and store strings in brackets
        stack<string> stk;
        // use one pass to decode the sting
        for(char& ch : s){
            // push all characters except ']'
            if(ch != ']'){
                stk.push(string(1,ch));
            }
            // when meet a ']' begin poping
            else{
                string str = "";
                string chars = getChars(stk);  // get a string from stack
                int num = getNum(stk);  // get a number from stack
                // decode the string by number and string
                for(int i = 0; i < num; ++i){
                    str += chars;
                }
                // push decoded string for further decode
                stk.push(str);
            }
        }
        // at last, all strings in stack are decoded strings
        return getChars(stk);
    }
};