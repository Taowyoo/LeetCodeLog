// https://leetcode.com/problems/surrounded-regions
// 130. Surrounded Regions

// dfs from all boarder cells
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