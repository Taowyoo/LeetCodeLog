/*
 * File: surrounded-regions.java
 * File Created: 2021-01-15 12:45:00 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/surrounded-regions
 * -----
 * Last Modified: 2021-01-17 12:14:09 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

// 130. Surrounded Regions

// Dfs from all boarder cells
class Solution {
    class Position{
        public Integer row;
        public Integer col;
        public Position(Integer r, Integer c){
            this.row = r;
            this.col = c;
        }
    }
    private Integer rowLen = 0;
    private Integer colLen = 0;
    /**
     * Dfs, mark all connected 'O's
     * @param board Given board
     * @param row Current row number
     * @param col Current row number
     */
    private void dfs(char[][] board, int row, int col){
        if(board[row][col] != 'O') return;
        board[row][col] = 'Y';
        if(row > 0){
            this.dfs(board, row - 1, col);
        }
        if(col > 0){
            this.dfs(board, row, col - 1);
        }
        if(row < this.rowLen - 1){
            this.dfs(board, row + 1, col);
        }
        if(col < this.colLen - 1){
            this.dfs(board, row, col + 1);
        }
    }
    public void solve(char[][] board) {
        // coner case
        if(board == null || board.length == 0) return;
        // create the list of border elements
        this.rowLen = board.length;
        this.colLen = board[0].length;
        List<Position> borders = new ArrayList<>();
        for(int r = 0; r < this.rowLen; ++r){
            borders.add(new Position(r,0));
            borders.add(new Position(r,this.colLen - 1));
        }
        for(int c = 1; c < this.colLen - 1; ++c){
            borders.add(new Position(0,c));
            borders.add(new Position(this.rowLen - 1,c));
        }
        // traverse border elements and dfs 'O's
        for (Position pos : borders) {
          this.dfs(board, pos.row, pos.col);
        }
        // fill all cells with target states
        for(int r = 0; r < this.rowLen; ++r){
            for(int c = 0; c < this.colLen; ++c){
                if(board[r][c] == 'O'){
                    board[r][c] = 'X';
                }
                if(board[r][c] == 'Y'){
                    board[r][c] = 'O';
                }
            }
        }
    }
}

/**
 * Same idea but use BFS
 */

public class Solution {
    protected Integer ROWS = 0;
    protected Integer COLS = 0;
  
    public void solve(char[][] board) {
      if (board == null || board.length == 0) {
        return;
      }
      this.ROWS = board.length;
      this.COLS = board[0].length;
  
      List<Pair<Integer, Integer>> borders = new LinkedList<Pair<Integer, Integer>>();
      // Step 1). construct the list of border cells
      for (int r = 0; r < this.ROWS; ++r) {
        borders.add(new Pair(r, 0));
        borders.add(new Pair(r, this.COLS - 1));
      }
      for (int c = 0; c < this.COLS; ++c) {
        borders.add(new Pair(0, c));
        borders.add(new Pair(this.ROWS - 1, c));
      }
  
      // Step 2). mark the escaped cells
      for (Pair<Integer, Integer> pair : borders) {
        this.BFS(board, pair.first, pair.second);
      }
  
      // Step 3). flip the cells to their correct final states
      for (int r = 0; r < this.ROWS; ++r) {
        for (int c = 0; c < this.COLS; ++c) {
          if (board[r][c] == 'O')
            board[r][c] = 'X';
          if (board[r][c] == 'E')
            board[r][c] = 'O';
        }
      }
    }
  
    protected void BFS(char[][] board, int r, int c) {
      LinkedList<Pair<Integer, Integer>> queue = new LinkedList<Pair<Integer, Integer>>();
      queue.offer(new Pair<>(r, c));
  
      while (!queue.isEmpty()) {
        Pair<Integer, Integer> pair = queue.pollFirst();
        int row = pair.first, col = pair.second;
        if (board[row][col] != 'O')
          continue;
  
        board[row][col] = 'E';
        if (col < this.COLS - 1)
          queue.offer(new Pair<>(row, col + 1));
        if (row < this.ROWS - 1)
          queue.offer(new Pair<>(row + 1, col));
        if (col > 0)
          queue.offer(new Pair<>(row, col - 1));
        if (row > 0)
          queue.offer(new Pair<>(row - 1, col));
      }
    }
  }
  
  
  class Pair<U, V> {
    public U first;
    public V second;
  
    public Pair(U first, V second) {
      this.first = first;
      this.second = second;
    }
  }
  