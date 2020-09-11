// https://leetcode.com/problems/string-to-integer-atoi/

// My solution
// Time: O(n)
// Space: O(1)
class Solution {
public:
    /**
     * @brief transform numeric string to int
     * 
     * @param str Numeric string
     * @return int Result int
     */
    int myAtoi(string str) {
        int res = 0;
        bool negative = false;  // variable for store whether number is negative or positive
        int lastNotNum = true;  // variable for marking lastChar if a number
        for( int i = 0; i<str.size();++i){
            if(isdigit(str[i])){
                // check whether current result is over INT Limitation
                if(res > INT_MAX/10) return negative ? INT_MIN : INT_MAX;
                else if(res == INT_MAX/10 && str[i] >= '8'){
                    return negative ? INT_MIN : INT_MAX;
                }
                // if meet a number, add it to result
                res *= 10;
                res += str[i] - '0';
                lastNotNum = false;
            }
            // check meet first negative or positive sign
            else if(lastNotNum && (str[i] == '-' || str[i] == '+')){
                lastNotNum = true;
                if(i + 1 < str.size() && isdigit(str[i+1]))  // sign only is available when there are number behind it
                    negative = str[i] == '-' ? true : false;
                else
                    break;
            }
            else if(lastNotNum && str[i] == ' '){  // ignore ' '
                lastNotNum = true;
                continue;
            }
            else{
                break;
            }
        }
        if(negative) res = -res; // let number negative if is negative
        return res;
    }
    
};

// Better improved one
class Solution {
public:
    /**
     * @brief transform numeric string to int
     * 
     * @param str Numeric string
     * @return int Result int
     */
    int myAtoi(string s) {
        int i=0;
        int ans = 0;
        int sign = 1;  
        for(; i< s.length() && s[i]==' '; ) i++;   // ignore ' '
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-' )  // set sign
                sign = -1;
            i++;
        }
        for(; i< s.length() && isdigit(s[i]);){
            int num = s[i] - '0';
            // check whether current result is over INT Limitation
            if(ans > INT_MAX / 10 || ans * 10 > INT_MAX - num){
                return sign ==1 ? INT_MAX : INT_MIN;
            }        
            ans = ans*10 + num;
            i++;
        }
        return ans * sign;
    }
};