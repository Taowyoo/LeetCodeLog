/*
 * File: 394.cpp
 * Created Date: 2021-03-08
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/decode-string/
 * -----
 * Last Modified: 2021-03-08T10:34:47-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */

#include <stack>
#include <string>
using namespace std;

class Solution {
  /**
   * @brief Get the Chars object
   *
   * @param stk
   * @return string
   */
  string getChars(stack<string> &stk) {
    string res = "";
    while (!stk.empty() && isalpha(stk.top().front())) {
      res = stk.top() + res;
      stk.pop();
    }
    if (!stk.empty() && stk.top().front() == '[')
      stk.pop();
    return res;
  }

  /**
   * @brief Get the Num object
   *
   * @param stk
   * @return int
   */
  int getNum(stack<string> &stk) {
    string res = "";
    while (!stk.empty() && isdigit(stk.top().front())) {
      res = stk.top() + res;
      stk.pop();
    }
    if (!stk.empty() && stk.top().front() == '[')
      stk.pop();
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
    for (char &ch : s) {
      // push all characters except ']'
      if (ch != ']') {
        stk.push(string(1, ch));
      }
      // when meet a ']' begin poping
      else {
        string str = "";
        string chars = getChars(stk); // get a string from stack
        int num = getNum(stk);        // get a number from stack
        // decode the string by number and string
        for (int i = 0; i < num; ++i) {
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

class Solution2 {
public:
  /**
   * @brief Use two stack, one for count number, one for string
   *
   * @param s coded string
   * @return string decoded string
   */
  string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString;
    int k = 0;
    for (auto ch : s) {
      if (isdigit(ch)) {
        k = k * 10 + ch - '0';
      } else if (ch == '[') {
        // push the number k to countStack
        countStack.push(k);
        // push the currentString to stringStack
        stringStack.push(currentString);
        // reset currentString and k
        currentString = "";
        k = 0;
      } else if (ch == ']') {
        string decodedString = stringStack.top();
        stringStack.pop();
        // decode currentK[currentString] by appending currentString k times
        for (int currentK = countStack.top(); currentK > 0; currentK--) {
          decodedString = decodedString + currentString;
        }
        countStack.pop();
        currentString = decodedString;
      } else {
        currentString = currentString + ch;
      }
    }
    return currentString;
  }
};

/**
 * @brief Use recursion
 *
 */
class Solution3 {
public:
  string decodeString(string s) {
    int index = 0;
    return decodeString(s, index);
  }
  string decodeString(const string &s, int &index) {
    string result;
    while (index < s.length() && s[index] != ']') {
      if (!isdigit(s[index]))
        result += s[index++];
      else {
        int k = 0;
        // build k while next character is a digit
        while (index < s.length() && isdigit(s[index]))
          k = k * 10 + s[index++] - '0';
        // ignore the opening bracket '['
        index++;
        string decodedString = decodeString(s, index);
        // ignore the closing bracket ']'
        index++;
        while (k-- > 0)
          result += decodedString;
      }
    }
    return result;
  }
};