// my solution
// generate pattern array for each string and put them into different group according by comparing the pattern
// Time: O(K^2N^2),  where N is the length of strs, and K is the maximum length of a string in strs.
// Space: O(NK)
// let n is number of strings, m is bumber of all input characters
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<array<int,27>> patterns;
        vector<vector<string>> res(1,vector<string>());
        for(string& str : strs){
            int num = matchPattern(str,patterns);
            if(num < res.size()){
                res[num].emplace_back(str);
            }
            else{
                res.emplace_back(vector<string>(1,str));
            }
        }
        return res;
    }
private:
    int matchPattern(string& str,vector<array<int,27>>& patterns){
        array<int,27> tmp_pattern = {0};
        for(char& c : str){
            ++tmp_pattern[c-'a'];
            ++tmp_pattern.back();
        }
        for(int i = 0; i < patterns.size(); ++i){
            if(patterns[i].back() != tmp_pattern.back()) continue;
            if(patterns[i] == tmp_pattern) return i;
        }
        patterns.emplace_back(tmp_pattern);
        return patterns.size() - 1;
    }
};


// other approaches:
// Approach 1: Categorize by Sorted String
// Intuition
// Two strings are anagrams if and only if their sorted strings are equal.
// Algorithm
// Maintain a map ans : {String -> List} where each key K is a sorted string, and each value is the list of strings from the initial input that when sorted, are equal to K.
// Time: O(NKlogK),  where N is the length of strs, and K is the maximum length of a string in strs.
// Space: O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }

};

// Approach 2: Categorize by Count
// Intuition

// Two strings are anagrams if and only if their character counts (respective number of occurrences of each character) are the same.

// Algorithm

// We can transform each string \text{s}s into a character count, \text{count}count, consisting of 26 non-negative integers representing the number of a's, b's, c's, etc. 
// We use these counts as the basis for our hash map.

// Time: O(NK),  where N is the length of strs, and K is the maximum length of a string in strs.
// Space: O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[sortLowercase(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string sortLowercase(string s) {
    int charExist[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        charExist[s[i] - 'a']++;
    }
    string res;
    int j = 0;
    while (j < 26) {
        if (charExist[j] == 0) {
            j++;
        }
        else {
            res.push_back(j + 'a');
            charExist[j]--;
        }
    }
    return res;
}
};
