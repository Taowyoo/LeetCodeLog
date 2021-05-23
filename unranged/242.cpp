// my solution
// use hash map to check whether t is an anagram of s
// Time: O(n)
// Space: O(n)
// let n is length of s
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> count;
        for(char c : s){
            ++count[c];
        }
        for(char c : t){
            if(count[c]==0) return false;
            else --count[c];
        }
        return true;
    }
};

// other approaches:
// Approach #1 (Sorting)
// Time: O(nlogn)
// Space: O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};

