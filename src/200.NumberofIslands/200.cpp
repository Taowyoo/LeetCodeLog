/*
 * File: 200.cpp
 * Created Date: 2021-03-08
 * Author: Nick Cao(caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/number-of-islands/
 * -----
 * Last Modified: 2021-03-08T10:08:54-08:00
 * Modified By: Nick Cao(caoyxsh@outlook.com)
 */

#include <vector>
using namespace std;

/**
 * @brief DFS
 * 
 */
class Solution1 {
    static constexpr int dr[4] = {1,-1,0,0};
    static constexpr int dc[4] = {0,0,1,-1};
    int R;
    int C;
    bool dfs(vector<vector<char>>& grid,int r, int c){
        if(r < 0 || c < 0 || r >= R || c >= C)
            return false;
        if(grid[r][c] == '1'){
            grid[r][c] = '0';
            for(int i = 0; i < 4 ; i++){
                dfs(grid,r+dr[i],c+dc[i]);
            }
            return true;
        }
        return false;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        R = grid.size();
        if(R==0) return 0;
        C = grid[0].size();
        if(C==0) return 0;
        int res = 0;
        for(int r = 0 ; r < R; r++){
            for(int c = 0; c < C;c++){
                if(dfs(grid,r,c)){
                    res++;
                }
            }
        }
        return res;
    }
};