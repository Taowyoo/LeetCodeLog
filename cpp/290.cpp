// my solution
// generate pattern array for two string
// the second one is generated according to each word
// Time: O(n)
// Space: O(n)
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // generate pattern array for pattern
        int index_p[26] = {0};
        vector<int> pattern_p(pattern.size());
        for(int i = 0; i < pattern.size(); ++i){
            if(index_p[pattern[i] - 'a']) pattern_p[i] = index_p[pattern[i] - 'a'];
            else index_p[pattern[i] - 'a'] = i + 1;
        }
        // generate pattern array for words
        vector<string> strs(process(str));
        if(strs.size() != pattern.size()) return false;
        unordered_map<string,int> index_s;
        vector<int> pattern_s(pattern.size());
        for(int i = 0; i < strs.size(); ++i){
            if(index_s[strs[i]]) pattern_s[i] = index_s[strs[i]];
            else index_s[strs[i]] = i + 1;
        }
        // compare pattern array
        for(int i = 0; i < pattern.size(); ++i){
            if(pattern_p[i] != pattern_s[i]) return false;
        }
        return true;
    }
private:
    vector<string> process(string& str){
        vector<string> strs;
        int i = 0;
        int l = 0;
        int r = 0;
        while(i < str.size()){
            while(i < str.size() && str[i] != ' ') ++i;
            r = i++;
            if(r > l){
                strs.emplace_back(str.substr(l,r - l));
                
            }
            l = r + 1;
        }
        return strs;
    }
};

// Approach 1: Two Hash Maps
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}

class Solution {
public:
    bool wordPattern(string pattern, string str) 
    {
        istringstream ss(str);
        string word;
        unordered_map<char, string> bmap;
        unordered_map<string, char>rbmap;

        for (char c : pattern)
        {
            if (! (getline(ss, word, ' ')))
                return false;
            if ( bmap.emplace(c,word).first->second != word)
                return false;
            if (rbmap.emplace(word,c).first->second != c)
                return false;
        }
        return ! getline(ss, word, ' ');   
    }
};