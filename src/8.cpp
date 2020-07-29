// my solution
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        bool negtive = false;
        int lastNotNum = true;
        for( int i = 0; i<str.size();++i){
            if(isdigit(str[i])){
                if(res > INT_MAX/10) return negtive ? INT_MIN : INT_MAX;
                else if(res == INT_MAX/10 && str[i] >= '8'){
                    return negtive ? INT_MIN : INT_MAX;
                }
                res *= 10;
                res += str[i] - '0';
                lastNotNum = false;
            }
            else if(lastNotNum && (str[i] == '-' || str[i] == '+')){
                lastNotNum = true;
                if(i + 1 < str.size() && isdigit(str[i+1]))
                    negtive = str[i] == '-' ? true : false;
                else
                    break;
            }
            else if(lastNotNum && str[i] == ' '){
                lastNotNum = true;
                continue;
            }
            else{
                break;
            }
        }
        if(negtive) res = -res;
        return res;
    }
    
};

// improved one
class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int ans = 0;
        int sign = 1;  
        for(; i< s.length() && s[i]==' '; ) i++; 
        if(s[i]=='-' || s[i]=='+'){
            if(s[i]=='-' )
                sign = -1;
            i++;
        }
        for(; i< s.length() && isdigit(s[i]);){
            int num = s[i] - '0';
            if(ans > INT_MAX / 10 || ans * 10 > INT_MAX - num){
                return sign ==1 ? INT_MAX : INT_MIN;
            }        
            ans = ans*10 + num;
            i++;
        }
        return ans * sign;
    }
};