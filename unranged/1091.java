// https://leetcode.com/problems/shortest-path-in-binary-matrix/
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