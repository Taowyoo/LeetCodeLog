/*
 * File: 6.cpp
 * Created Date: 2020-07-29
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/zigzag-conversion/
 * -----
 * Last Modified: 2021-01-18T13:21:48-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */

// My solution
// Time: O(n)
// Space: O(n)
// Stimulate draw zigzag on a 2D array then print out the string
class Solution {
public:
    /**
     * @brief Transform given string into ZigZag form and them output it line by line
     * 
     * @param s Given string
     * @param numRows Row number for ZigZag
     * @return string Result string
     */
    string convert(string s, int numRows) {
        // corner case
        if(s.size()<2 || numRows == 1) return s;
        int n = s.size();
        // for each 'V' part in ZigZag there are (numRows * 2 - 2) numbers, and represent (numRows - 1) columns
        // for example:
        // #     *
        // #   # *
        // # #   *
        // #     *
        // there are 4 * 2 - 2 = 6 '#' and they take 4 - 1 = 3 columns
        int width = (n / (numRows * 2 - 2)) * (numRows - 1);  // compute width
        // check whether there are extra columns
        int p = n % (numRows * 2 - 2); 
        if(p > 0 && p <= numRows) ++width;  // there is only another column which is the left column in a 'V'
        else if(p > numRows) width += p -  numRows + 1; // there are extra columns except the left column in a 'V'

        // arrange a canvas filled with #, and draw string in ZigZag pattern on it
        vector<vector<char>> canvas(numRows, vector<char>(width,'#'));
        int x = 0, y = 0;
        for(int i = 0; i < s.size(); ++i){
            if((i / (numRows - 1)) % 2 == 0){
                canvas[x++][y] = s[i];
            }else{
                canvas[x--][y++] = s[i];
            }
        }
        // fill the original string with new order by traversing the canvas
        int i = 0;
        for(auto& row : canvas){
            for(auto& ch : row){
                if(ch != '#') s[i++] = ch;
            }
        }
        return s;
    }
};

// Same method but better approach
// Time: O(n)
// Space: O(n)
// By iterating through the string from left to right, 
//   we can easily determine which row in the Zig-Zag pattern that a character belongs to.
class Solution {
public:
    /**
     * @brief Transform given string into ZigZag form and them output it line by line
     * 
     * @param s Given string
     * @param numRows Row number for ZigZag
     * @return string Result string
     */
    string convert(string s, int numRows) {
        // corner case
        if (numRows == 1) return s;
        // use min(numRows,len(s)) lists to represent the non-empty rows of the Zig-Zag Pattern.
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;  // for recording our visit direction
        // stimulate the read order in ZigZag pattern
        for (char c : s) {
            rows[curRow] += c; // write character into corresponding row
            // when meet the top or bottom row, we should change over visit direction
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;  // visite next above or below character
        }
        // get result string by connecting all rows line by line
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
    /**
     * @brief Transform given string into ZigZag form and them output it line by line
     * 
     * @param s Given string
     * @param numRows Row number for ZigZag
     * @return string Result string
     */
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        string ret;
        int n = s.size();
        int cycleLen = 2 * numRows - 2; // the interval between each character on original string
        // same idea to above solution, but in current case we just visit directly
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
