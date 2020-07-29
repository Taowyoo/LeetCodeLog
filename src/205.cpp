// my solution
// generate two pattern array for two string
// then compare two array to detect whether they are isomorphic.
// Time: O(n)
// Space: O(n)
// let n is length of stirng s
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int index_s[256] = {0};
        int index_t[256] = {0};
        vector<int> pattern_s(s.size());
        vector<int> pattern_t(t.size());
        for(int i = 0; i < s.size(); ++i){
            if(index_s[s[i]]) pattern_s[i] = index_s[s[i]];
            else index_s[s[i]] = i + 1;
        }
        for(int i = 0; i < t.size(); ++i){
            if(index_t[t[i]]) pattern_t[i] = index_t[t[i]];
            else index_t[t[i]] = i + 1;
        }
        for(int i = 0; i < s.size(); ++i){
            if(pattern_s[i] != pattern_t[i]) return false;
        }
        return true;
    }
};

// an improved approach with same idea
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        array<int, 256> m1, m2;
        m1.fill(-1);
        m2.fill(-1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};