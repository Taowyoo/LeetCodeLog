// my solution
// Time: O(n)
// Space: O(n)
// stimulate draw zigzag on a 2D array then print out the string
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()<2 || numRows == 1) return s;
        int n = s.size();
        int width = (n / (numRows*2-2)) *(numRows - 1);
        int p =n%(numRows*2-2);
        if(p > 0 && p <= numRows) ++width;
        else if(p > numRows) width += p -  numRows + 1;
        vector<vector<char>> canvas(numRows, vector<char>(width,'#'));
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); ++i){
            if((i / (numRows - 1)) % 2 == 0){
                canvas[x++][y] = s[i];
            }else{
                canvas[x--][y++] = s[i];
            }
        }
        int i = 0;
        for(auto& row : canvas){
            for(auto& ch : row){
                if(ch != '#') s[i++] = ch;
            }
        }
        return s;
    }
};

// same method but better approach
// Time: O(n)
// Space: O(n)
// By iterating through the string from left to right, 
//   we can easily determine which row in the Zig-Zag pattern that a character belongs to.
// We can use min(numRows,len(s)) lists to represent the non-empty rows of the Zig-Zag Pattern.
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};

// Approach 2: Visit by Row
// Visit the characters in the same order as reading the Zig-Zag pattern line by line.
// Visit all characters in row 0 first, then row 1, then row 2, and so on...
// For all whole numbers kk,
// Characters in row 00 are located at indexes k(2⋅numRows−2)
// Characters in row numRows−1 are located at indexes k(2⋅numRows−2)+numRows−1
// Characters in inner row i are located at indexes k(2⋅numRows−2)+i and (k+1)(2⋅numRows−2)−i.
// Time: O(n)
// Space: O(n), O(1) if return string is not considered extra space.
class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    ret += s[j + cycleLen - i];
            }
        }
        return ret;
    }
};
