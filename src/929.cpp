// my solution
// Time & space: O(n).
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int ans = 0;
        set<string> mailset;
        for(auto& str: emails){
            remove(str);
            mailset.emplace(str);
        }
        return mailset.size();
    }
private:
    void remove(string & str){
        int i = 0, j = 0;
        int N = str.size();
        bool beforeAT = true;
        bool beforeADD = true;
        while(i < N){
            if(str[i] == '@'){
                beforeAT = false;
            }
            if(str[i] == '+') beforeADD = false;
            
            
            if(beforeAT){
                if(beforeADD){
                    if(str[i] != '.'){
                        str[j] = str[i];
                        ++j;
                    }
                }
            }else{
                str[j] = str[i];
                ++j;
            }
            ++i;
        }
        str.resize(j);
    }
};

// concise solution
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(string &email : emails) {
            string cleanEmail;
            for(char c : email) {
                if(c == '+' || c == '@') break;
                if(c == '.') continue;
                cleanEmail += c;
            }
            cleanEmail += email.substr(email.find('@'));
            st.insert(cleanEmail);
        }
        return st.size();
    }

};