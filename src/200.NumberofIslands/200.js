/*
 * @Author: Nick Cao
 * @Date: 2021-05-27 10:47:47
 * @LastEditTime: 2021-05-28 16:40:22
 * @LastEditors: Nick Cao
 * @Description: 
 * @FilePath: \LeetCodeLog\src\200. Number of Islands\200.js
 */

/**
 * DFS Solution
 * @param {character[][]} grid
 * @return {number}
 */
 var numIslands = function(grid) {
    let directions = [[1,0],[-1,0],[0,1],[0,-1]];
    let R = grid.length;
    if (R===0) {
        return 0;
    }
    let C = grid[0].length;
    if (C===0) {
        return 0;
    }
    function dfs(grid,x,y){
        if(x < 0 || y < 0 || x >= R || y >= C){
            return;
        }
        if(grid[x][y] === '0'){
            return;
        }
        grid[x][y] = '0';
        
        for(let dir of directions){
            dfs(grid,x+dir[0],y+dir[1]);
        }
    }
    let res = 0;
    for (let i = 0; i < R; i++){
        for (let j = 0; j < C; j++){
            if (grid[i][j]==='1'){
                dfs(grid,i,j);
                res++;
            }
        }
    }
    return res;
};