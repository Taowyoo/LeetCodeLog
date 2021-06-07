/*
 * File: sliding-puzzle.java
 * File Created: 2021-01-15 12:44:55 -08:00
 * Author: Taowyoo (caoyxsh@outlook.com)
 * Brief: https://leetcode.com/problems/sliding-puzzle/
 * -----
 * Last Modified: 2021-01-17 12:31:02 -08:00
 * Modified By: Taowyoo (caoyxsh@outlook.com>)
 * -----
 * Copyright 2020 - 2021
 */

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
        // use bfs to check whether can reach given board state
        // also count step
        bfs(board);
        // System.out.println(this.skip);
        return this.res;
    }
}

/**
 * A* Search
 */

class Solution {
    public int slidingPuzzle(int[][] board) {
        int R = board.length, C = board[0].length;
        int sr = 0, sc = 0;

        //Find sr, sc
        search:
            for (sr = 0; sr < R; sr++)
                for (sc = 0; sc < C; sc++)
                    if (board[sr][sc] == 0)
                        break search;

        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        PriorityQueue<Node> heap = new PriorityQueue<Node>((a, b) ->
            (a.heuristic + a.depth) - (b.heuristic + b.depth));
        Node start = new Node(board, sr, sc, 0);
        heap.add(start);

        Map<String, Integer> cost = new HashMap();
        cost.put(start.boardstring, 9999999);

        String target = Arrays.deepToString(new int[][]{{1,2,3}, {4,5,0}});
        String targetWrong = Arrays.deepToString(new int[][]{{1,2,3}, {5,4,0}});

        while (!heap.isEmpty()) {
            Node node = heap.poll();
            if (node.boardstring.equals(target))
                return node.depth;
            if (node.boardstring.equals(targetWrong))
                return -1;
            if (node.depth + node.heuristic > cost.get(node.boardstring))
                continue;

            for (int[] di: directions) {
                int nei_r = di[0] + node.zero_r;
                int nei_c = di[1] + node.zero_c;

                // If the neighbor is not on the board or wraps incorrectly around rows/cols
                if ((Math.abs(nei_r - node.zero_r) + Math.abs(nei_c - node.zero_c) != 1) ||
                        nei_r < 0 || nei_r >= R || nei_c < 0 || nei_c >= C)
                    continue;

                int[][] newboard = new int[R][C];
                int t = 0;
                for (int[] row: node.board)
                    newboard[t++] = row.clone();

                // Swap the elements on the new board
                newboard[node.zero_r][node.zero_c] = newboard[nei_r][nei_c];
                newboard[nei_r][nei_c] = 0;

                Node nei = new Node(newboard, nei_r, nei_c, node.depth+1);
                if (nei.depth + nei.heuristic >= cost.getOrDefault(nei.boardstring, 9999999))
                    continue;
                heap.add(nei);
                cost.put(nei.boardstring, nei.depth + nei.heuristic);
            }
        }

        return -1;
    }
}

class Node {
    int[][] board;
    String boardstring;
    int heuristic;
    int zero_r;
    int zero_c;
    int depth;
    Node(int[][] B, int zr, int zc, int d) {
        board = B;
        boardstring = Arrays.deepToString(board);

        //Calculate heuristic
        heuristic = 0;
        int R = B.length, C = B[0].length;
        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c) {
                if (board[r][c] == 0) continue;
                int v = (board[r][c] + R*C - 1) % (R*C);
                // v/C, v%C: where board[r][c] should go in a solved puzzle
                heuristic += Math.abs(r - v/C) + Math.abs(c - v%C);
            }
        heuristic /= 2;
        zero_r = zr;
        zero_c = zc;
        depth = d;
    }
}