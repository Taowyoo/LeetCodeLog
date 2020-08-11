// my solution
// time O(n*n)
// memory O(n) -> n is the length of result string
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for(int i = 0 ; i < n - 1 ; ++i){
            // process str
            str = process(str);
        }
        return str;
    }
    string process(string& str){
        string res;
        int num = 1;
        for(int i = 0; i < str.size(); ++i){
            if(i + 1 == str.size()){
               res += char('0'+num);
               res += str[i];
               break;
            }
            if(str[i+1] != str[i]){
                res += char('0'+num);
                res += str[i];
                num = 1;
            }
            else{
                ++num;
            }

        }
        return res;
    }
};
// same idea, improved one
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string cur = "";
            for (int i = 0; i < res.size(); i++) {
                int count = 1;
                 while ((i + 1 < res.size()) && (res[i] == res[i + 1])){
                    count++;    
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};