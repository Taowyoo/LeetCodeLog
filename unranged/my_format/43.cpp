// my solution
// time: O(m^2) : m == max(num1.size(), num2.size())
// memory: O(N) : N is length of result string
// description: stimulate how human multiply two numbers on paper
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num2 == "0" || num1 == "0") return "0";
        int dig = 0;
        string res = "";
        string muti;
        for(int i = num2.size() - 1; i >= 0; --i){
            muti = multiOne(num1, num2[i], dig);
            res = add(res,muti);
            ++dig;
        }
        return res;
    }
private:
    string add(string& num1, string& num2){
        string res ="";
        int c = 0, i = num1.size() - 1, j = num2.size() - 1;
        while(i >= 0 || j >= 0 || c > 0){
            c += i >= 0 ? num1[i--] - '0' : 0;
            c += j >= 0 ? num2[j--] - '0' : 0;
            res += char(c % 10 + '0');
            c /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiOne(string& num1, char num2, int dig){
        string res = "";
        int c = 0, i = num1.size() - 1;
        int muti = num2 - '0';
        while(i >= 0 || c > 0){
            c += i >= 0 ? (num1[i--] - '0') * muti : 0;
            res += char(c % 10 + '0');
            c /= 10;
        }
        reverse(res.begin(),res.end());
        res += string(dig,'0');
        return res;
    }
};

// better solution
// time: O(m * n)
// memory: O(m + n)
// explaination about i j: num1[i] * num2[j] will be placed at indices [i + j`, `i + j + 1]
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans(m + n, '0');
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';
                ans[i + j] += sum / 10;
            }
        }
        size_t startpos = ans.find_first_not_of("0");
        if (string::npos != startpos) {
            return ans.substr(startpos);
        }
        return "0";
    }
};