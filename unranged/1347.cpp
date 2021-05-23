// my solution
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {};
        for(int i = 0; i < s.size(); ++i){
            ++count[s[i]-'a'];
            --count[t[i]-'a'];
        }
        int res = 0;
        for(int i = 0; i < 26; ++i){
            if(count[i] > 0)
                res += count[i];
        }
        return res;
    }
};