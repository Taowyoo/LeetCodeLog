class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        getResults(res,"",0,0,n);
        return res;
    }
    void getResults(vector<string>& res,string cur, int open, int close, int n){
        if(cur.size() == n*2){
            res.emplace_back(cur);
            return;
        }
        if(open<n){
            getResults(res,cur + "(",open+1,close,n);
        }
        if(close < open){
            getResults(res,cur + ")",open,close+1,n);
        }
    }
};