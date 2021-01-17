/*
 * File: shortest-path-in-binary-matrix.java
 * File Created: 2021-01-15 12:44:53 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/shortest-path-in-binary-matrix/
 * -----
 * Last Modified: 2021-01-17 12:40:12 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

 // 1091. Shortest Path in Binary Matrix

// my solution
// bfs
class Solution {
    class Cell{
        public int row;
        public int col;
        public Cell(int r, int c){
            this.row = r;
            this.col = c;
        }
    }
    /**
     * bfs from left-top, record current step on visited '0' cell
     * @param grid Given grid
     * @return int Length of Shortest Path
     */
    private int bfs(int [][] grid){
        int ans = 0;
        LinkedList<Cell> queue = new LinkedList<>();
        queue.offer(new Cell(0,0));
        grid[0][0] = 1;
        while(!queue.isEmpty()){
            Cell cur = queue.pollFirst();
            int row = cur.row;
            int col = cur.col;
            int path = grid[row][col];
            if(row == N - 1 && col == N - 1) return path;
            // visit neighbor
            for(int i = 0; i < 8; ++i){
                int r = row + dr[i];
                int c = col + dc[i];
                if(r < 0 || c < 0 || r >= N || c >= N) continue;
                if(grid[r][c] == 0){
                    queue.offer(new Cell(r,c));
                    grid[r][c] = path + 1;
                }
            }
        }
        return -1;
    }
    private int dr[] = {-1, 1, 0, 0,-1, 1,-1, 1};
    private int dc[] = { 0, 0,-1, 1,-1,-1, 1, 1};
    private int N = 0;
    /**
     * Get Shortest Path in Binary Matrix
     * @param grid Given grid
     * @return int Length of Shortest Path
     */
    public int shortestPathBinaryMatrix(int[][] grid) {
        // corner case
        if(grid == null || grid.length == 0) return 0;
        this.N = grid.length;
        if(grid[0][0] == 1 || grid[N - 1][N - 1] == 1) return -1;

        return bfs(grid);
    }
}


/**
 * A*
 */
class Solution {
    
    // Candidate represents a possible option for travelling to the cell
    // at (row, col).
    class Candidate {
        
        public int row;
        public int col;
        public int distanceSoFar;
        public int totalEstimate;
        
        public Candidate(int row, int col, int distanceSoFar, int totalEstimate) {
            this.row = row;
            this.col = col;
            this.distanceSoFar = distanceSoFar;
            this.totalEstimate = totalEstimate;
        }
    }
    
    
    private static final int[][] directions = 
        new int[][]{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        
        // Firstly, we need to check that the start and target cells are open.
        if (grid[0][0] != 0 || grid[grid.length - 1][grid[0].length - 1] != 0) {
            return -1;
        }
        
        // Set up the A* search.
        Queue<Candidate> pq = new PriorityQueue<>((a,b) -> a.totalEstimate - b.totalEstimate);
        pq.add(new Candidate(0, 0, 1, estimate(0, 0, grid)));
        
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        
        // Carry out the A* search.
        while (!pq.isEmpty()) {
            
            Candidate best = pq.remove();
            
            // Is this for the target cell?
            if (best.row == grid.length - 1 && best.col == grid[0].length - 1) {
                return best.distanceSoFar;
            }
            
            // Have we already found the best path to this cell?
            if (visited[best.row][best.col]) {
                continue;
            }
            
            visited[best.row][best.col] = true;
            
            for (int[] neighbour : getNeighbours(best.row, best.col, grid)) {
                int neighbourRow = neighbour[0];
                int neighbourCol = neighbour[1];
                
                // This check isn't necessary for correctness, but it greatly
                // improves performance.
                if (visited[neighbourRow][neighbourCol]) {
                    continue;
                }
                
                // Otherwise, we need to create a Candidate object for the option
                // of going to neighbor through the current cell.
                int newDistance = best.distanceSoFar + 1;
                int totalEstimate = newDistance + estimate(neighbourRow, neighbourCol, grid);
                Candidate candidate = 
                    new Candidate(neighbourRow, neighbourCol, newDistance, totalEstimate);
                pq.add(candidate);
            }   
        }
        // The target was unreachable.
        return -1;  
    }
    
    private List<int[]> getNeighbours(int row, int col, int[][] grid) {
        List<int[]> neighbours = new ArrayList<>();
        for (int i = 0; i < directions.length; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (newRow < 0 || newCol < 0 || newRow >= grid.length 
                    || newCol >= grid[0].length
                    || grid[newRow][newCol] != 0) {
                continue;    
            }
            neighbours.add(new int[]{newRow, newCol});
        }
        return neighbours; 
    }
    
    // Get the best case estimate of how much further it is to the bottom-right cell.
    private int estimate(int row, int col, int[][] grid) {
        int remainingRows = grid.length - row - 1;
        int remainingCols = grid[0].length - col - 1;
        return Math.max(remainingRows, remainingCols);
    }
}
