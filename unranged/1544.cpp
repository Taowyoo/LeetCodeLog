// my solution using list
// Time: O(n)
// Space: O(n)
class Solution {
public:
    string makeGood(string s) {
        list<char> str_list(s.begin(),s.end());
        auto le = str_list.begin();
        auto ri = ++str_list.begin();
        while(ri!=str_list.end()){
            cout << (*le)<<","<<(*ri)<<endl;
            if(abs((*le)-(*ri)) == interval){
                auto next = str_list.erase(le);
                ri = str_list.erase(next);
                if(str_list.empty()) break;
                if(ri == str_list.begin()){
                    le = str_list.begin();
                    ri = ++ri;
                }
                else{
                    le = ri;
                    le = --le;
                }
            }
            else{
                le = ri;
                ri = ++ri;
            }
        }
        return string(str_list.begin(), str_list.end());
    }
private:
    const int interval = abs('A' - 'a');
};
//========================================================================
// Tricky
class Solution {
public:
    string makeGood(string s) {
        int l = s.length();
        string res = "";
        for(int i=0; i<l; i++){
            if(res.length() == 0) res += s[i];
            else if(abs(res.back() - s[i]) == 32){
                res.pop_back();
            }
            else res += s[i];
        }
        return res;
    }
};
//========================================================================
// Two pinter one pass
string makeGood(string s, int p = 0) {
    for (int i = 0; i < s.size(); ++i) {
        if (p >= 1 && s[i] != s[p - 1] && tolower(s[i]) == tolower(s[p - 1]))
            p -= 1;
        else
            s[p++] = s[i];
    }
    return s.substr(0, p);
}