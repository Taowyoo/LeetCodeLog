// my solution
// my implementation of KMP Algorithm
// time: O(n+m)
// memory: O(n)
// m: length of haystack, n: length of needle
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(needle.size() > haystack.size()) return -1;
        vector<int> LPS = getLPS(needle);
        int i = 0;
        int j = 0;
        while(i < haystack.size()){
            while(j < needle.size()){
                if(needle[j] != haystack[i]){
                    if(j > 0){
                        j = LPS[j-1];
                    }
                    else {
                        ++i;
                        break;
                    }
                }
                else{
                    ++i;
                    ++j;
                }
            }
            if(j == needle.size()) return i - needle.size();
        }
        return -1;
    }
    vector<int> getLPS(string str){
        int i = 1, j = 0;
        vector<int> lps(str.size(),0);
        while(i < str.size()){
            while(j && str[i] != str[j]){
                j = lps[j-1];
            }
            if(str[i] == str[j]){
                ++j;
            }
            lps[i++] = j;
        }
        return lps;
    }
};

// Brute-Force
// time: O(n*m)
// memory: O(1)
// m: length of haystack, n: length of needle
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (; j < n; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};

// other's KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }
private:
    vector<int> kmpProcess(string needle) {
        int n = needle.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                lps[i++] = ++len;
            } else if (len) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }
};