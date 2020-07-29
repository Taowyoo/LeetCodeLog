// use hash table
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int,int> count;
        for(char c : s){
            ++count[c-'a'];
        }
        for(char c : t){
            --count[c-'a'];
        }
        for(auto& kv : count){
            if(kv.second) return kv.first + 'a';
        }
        return '#';
    }
};

// bit manipulation
class Solution {
public:
    char findTheDifference(string s, string t) {
        char count = 0;
        for(char c : s){
            count ^= c;
        }
        for(char c : t){
            count ^= c;
        }
        return count;
    }
};