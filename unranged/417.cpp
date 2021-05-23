// https://leetcode.com/problems/pacific-atlantic-water-flow/
// 417. Pacific Atlantic Water Flow
// my solution

// Use dfs to update each cell state
// Finally, get all required cells
class Solution {
    enum state{
        None = 0x000,
        Pacific = 0x001,
        Atlantic = 0x002,
        Both = 0x003
    };
    vector<vector<int>> res;
    vector<vector<state>> record;
    constexpr static const int d_r[4] = {0,0,1,-1};
    constexpr static const int d_c[4] = {1,-1,0,0};
    int m;
    int n;
    /**
     * @brief Check and update curent cell state, and recursively check it's neighbour
     * 
     * @param matrix Given matrix
     * @param row Current row number
     * @param col Current column number
     * @param src_water Last cell water level
     * @param src Last cell water state
     */
    void check(vector<vector<int>>& matrix, int row, int col, int src_water = -1, state src = None){
        if(row < 0 || col < 0) return;
        if(row >= m || col >= n) return;
        if(row == 0 || col == 0)
            record[row][col] = (state)((int)record[row][col] | (int)Pacific);
        if(row == m - 1 || col == n - 1)
            record[row][col] = (state)((int)record[row][col] | (int)Atlantic);
            
        if(src_water <= matrix[row][col] && src != record[row][col]){
            record[row][col] = (state)((int)record[row][col] | (int)src);
            for(int i = 0; i < 4; ++i){
                check(matrix, row + d_r[i], col + d_c[i], matrix[row][col], record[row][col]);
            }
        }
            
        
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        // coner case
        if(matrix.empty()) return res;
        m = matrix.size();
        n = matrix[0].size();
        // make a matreix to store the state of each point (where it can flow to)
        // 3 state: P, A, Both
        record.resize(m, vector<state>(n, None));
        // Traverse matrix with dfs
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                check(matrix, i, j);
            }
        }
        // check(matrix, 0, 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(record[i][j]  == Both)
                    res.emplace_back(vector<int>{i,j});
            }
        }
        return res;
    }
};