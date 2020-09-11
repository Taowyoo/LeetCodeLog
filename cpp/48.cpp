// https://leetcode.com/problems/rotate-image/

// My solution
// process from outermost elements into inner elements
// for each step process one layer
class Solution {
    /**
     * @brief rotate the one layer of numbers in matrix
     * 
     * @param i the layer number
     * @param len the number need to rotate on each side
     * @param matrix number matrix
     */
    void rotate(int i, int len, vector<vector<int>>& matrix){
        // if the length <= 1, we do not need to do anything
        if(len < 2) return; 
        int hi = i + len - 1;
        // swap first len - 1 numbers at top with those at right
        for(int j = 0; j < len - 1; ++j){
            int xs = i;
            int ys = i + j;
            
            int xt = i + j;
            int yt = hi;
            swap(matrix[xs][ys], matrix[xt][yt]);
        }
        // swap first len - 1 numbers at bottom with those at left
        for(int j = 0; j < len - 1; ++j){
            int xs = hi;
            int ys = hi - j;
            
            int xt = hi - j;
            int yt = i;
            swap(matrix[xs][ys], matrix[xt][yt]);
        }
        // swap first len - 1 numbers at top with those at bottom
        for(int j = 0; j < len - 1; ++j){
            int xs = i;
            int ys = i + j;
            
            int xt = hi;
            int yt = hi - j;
            swap(matrix[xs][ys], matrix[xt][yt]);
        }
        
    }
public:
    /**
     * @brief rotate the image(in number form) by 90 degrees (clockwise)
     * 
     * @param matrix number matrix
     */
    void rotate(vector<vector<int>>& matrix) {
        // process from outermost elements into inner elements
        for(int i = 0; i < matrix.size() / 2; ++i){
            rotate(i, matrix.size() - i * 2, matrix);
        }
    }
};

// Approach 1 : Transpose and then reverse
// transpose the matrix first and then reverse each row
class Solution {
public:
    /**
     * @brief rotate the image(in number form) by 90 degrees (clockwise)
     * 
     * @param matrix number matrix
     */
    void rotate(vector<vector<int>> &matrix){
        int n = matrix.size();

        // transpose matrix
        for (int i = 0; i < n; i++) {
          for (int j = i; j < n; j++) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = tmp;
          }
        }
        // reverse each row
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
          }
        }
    }
};

// Approach 2 : Rotate four rectangles
// tips: rotate them using a temp list of 4 elements.
class Solution {
public:
    /**
     * @brief rotate the image(in number form) by 90 degrees (clockwise)
     * 
     * @param matrix number matrix
     */
    void rotate(vector<vector<int>> &matrix){
        int n = matrix.size();
        for (int i = 0; i < n / 2 + n % 2; i++){
            for (int j = 0; j < n / 2; j++){
                int tmp[4] = {};
                int row = i;
                int col = j;
                // put four number at corners into temp array
                for (int k = 0; k < 4; k++){
                    tmp[k] = matrix[row][col];
                    int x = row;
                    row = col;
                    col = n - 1 - x;
                }
                // put four number from temp array into four corners at needed position 
                for (int k = 0; k < 4; k++){
                    matrix[row][col] = tmp[(k + 3) % 4];
                    int x = row;
                    row = col;
                    col = n - 1 - x;
                }
            }
        }
    }
};