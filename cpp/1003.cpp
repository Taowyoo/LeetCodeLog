// my solution
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isValid(string S) {
        int a(0),b(0);
        char last = S[0];
        for(char ch : S){
            switch(ch){
                case 'a':{
                    ++a;
                    break;
                }case 'b':{
                    ++b;
                    --a;
                    if(a<0 || last=='b') return false;
                    break;
                }case 'c':{
                    --b;
                    if(b<0 || last=='a') return false;
                    break;
                }
            }
            last = ch;
        }
        return (a==0&&b==0)?true:false;
    }
};
// stack solution
// Time complexity: O(n)
// Space complexity: O(n)
// use vector as a stack
bool isValid(string S) {
    vector<char> stack;
    for (char c : S) {
        if (c == 'c') {
            int n = stack.size();
            if (n < 2 || stack[n - 1] != 'b' || stack[n - 2] != 'a') return false;
            stack.pop_back(), stack.pop_back();
        } else {
            stack.push_back(c);
        }
    }
    return stack.size() == 0;
}
// use std::stack
class Solution {
public:
    bool isValid(string t){
        stack<char> s;
        for(int i = 0; i < t.length(); i++){
            if(t[i] == 'c'){
                if(s.size() < 2) return false;
                char e1 = s.top();
                s.pop();
                char e2 = s.top();
                s.pop();
                if(e1 != 'b' || e2 != 'a') return false;
            }else{
                s.push(t[i]);
            }   
        }
        return s.empty()?true:false;
    }
};