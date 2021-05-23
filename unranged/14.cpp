// my solution
// Time complexity : O(S)
// Space complexity : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        if(strs[0] == "") return "";
        string prefix("");
        int i = 0;
        char cur;
        bool notEnd = true; 
        while(notEnd && i < strs[0].size()){
            cur = strs[0][i];
            for(string& str : strs){
                if(i < str.size()){
                    if(str[i] != cur){
                        notEnd = false;
                        break;
                    }
                }else{
                    notEnd = false;
                    break;
                }
            }
            if(notEnd) prefix.push_back(cur);
            ++i;
        }
        
        return prefix;
        
    }
};

// Vertical scanning
// Time complexity : O(S)
// Space complexity : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        for (int i = 0; i < strs[0].size() ; i++){
            char c = strs[0].at(i);
            for (int j = 1; j < strs.size(); j ++) {
                if (i == strs[j].size() || strs[j].at(i) != c)
                    return strs[0].substr(0, i);             
            }
        }
        return strs[0];
    }
};
