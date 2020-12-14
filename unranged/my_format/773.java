// https://leetcode.com/problems/sliding-puzzle/
// 773. Sliding Puzzle

// my solution
// bfs
class Solution {
    private int res = -1;
    // private int skip = 0;
    private int maxStep = 6 * 5 * 4 * 3 * 2 * 1 / 2; // 6!/2!
    /**
     * Structure to store 
     */
    class Cell{
        public int row;
        public int col;
        public Cell(int r, int c){
            this.row = r;
            this.col = c;
        }
        public boolean equals(Cell cell){
            return this.row == cell.row && this.col == cell.col;
        }
    }
    private boolean isSame(int[][] board1, int[][] board2){
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                if(board1[i][j] != board2[i][j]) return false;
            }
        }
        return true;
    }
    private int[][] clone(int[][] src){
        int [][] ret = new int[src.length][];
        for(int i = 0; i < src.length; i++)
            ret[i] = src[i].clone();
        return ret;
    }
    private String toStr(int[][] src){
        String ret = "";
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 3; ++j){
                ret += String.valueOf(src[i][j]);
            }
        }
        return ret;
    }
    /**
     * Use bfs to check whether given board can be moved from finished state: [[1,2,3],[4,5,0]]
     * @param board Given board
     */
    private void bfs(int[][] board){
        int[][] original = {{1,2,3},{4,5,0}};
        LinkedList<Cell> queue = new LinkedList<>();
        HashMap<Cell,int[][]> states = new HashMap<Cell,int[][]>();
        Set<String> seen = new HashSet<>();
        queue.offer(new Cell(1,2));
        states.put(queue.peekFirst(),original);
        int step = 0;
        while(step <= maxStep){
            int sz = queue.size();
            while(sz-- > 0){
                Cell cur = queue.pollFirst();
                int[][] curBoard = states.get(cur);
                if(seen.contains(this.toStr(curBoard))){
                    continue;
                }
                seen.add(this.toStr(curBoard));
                
                if (isSame(curBoard,board)){
                    this.res = step;
                    return;
                }
                // move around
                for(int i = 0; i < 4; ++i){
                    int r = cur.row + dr[i];
                    int c = cur.col + dc[i];
                    if(r < 0 || c < 0 || r > 1 || c > 2) continue; 
                    Cell next = new Cell(r, c);
                    queue.offer(next);
                    int[][] nextboard = this.clone(curBoard);
                    nextboard[cur.row][cur.col] = nextboard[r][c];
                    nextboard[r][c] = 0;
                    states.put(next,nextboard);
                }
            }
            ++step;
        }
        return;
    }
    private int[] dr = {1,-1,0,0};
    private int[] dc = {0,0,1,-1};
    public int slidingPuzzle(int[][] board) {
        
        int[][] original = {{1,2,3},{4,5,0}};
        
        // use bfs to check whether can reach given board state
        // also count step
        bfs(board);
        // System.out.println(this.skip);
        return this.res;
    }
}