import java.util.ArrayList;
import java.util.LinkedList;

/*
 * @lc app=leetcode id=909 lang=java
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution {
    private int bfs(){
        LinkedList<Integer> queue = new LinkedList<>();
        Set<Integer> seen = new HashSet<>();
        queue.offer(1);
        int moves = 0;
        while(!queue.isEmpty()){
            int len = queue.size();
            for(int i = 0; i < len; ++i){
                int cur = queue.pollFirst();
                
                if(seen.contains(cur)) continue;
                seen.add(cur);
                
                if(cur == NN){
                    return moves;
                }
                for(int j = 1; j <= 6 && cur + j <= NN; ++j){
                    if(jump.get(cur + j) == -1){
                        queue.offer(cur + j);
                    }
                    else{
                        queue.offer(jump.get(cur + j));
                    }
                }
            }
            ++moves;
        }
        return -1;
    }
    private int NN = 0;
    private int N = 0;
    private ArrayList<Integer> jump;
    public int snakesAndLadders(int[][] board) {
        this.N = board.length;
        this.NN = N*N;
        // create 1-D jump List 
        this.jump = new ArrayList<Integer>();
        this.jump.add(-1);
        int r = 0, c = 0;
        for(int i = 0; i < this.NN; ++i){
            this.jump.add(board[N - 1 - r][c]);
            if(r % 2 == 0){
                ++c;
            }
            else{
                --c;
            }
            if(c >= N){
                c = N - 1;
                ++r;
            }
            if(c < 0){
                c = 0;
                ++r;
            }
        }
        return bfs();
    }
}
// @lc code=end

