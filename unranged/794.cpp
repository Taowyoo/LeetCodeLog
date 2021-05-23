// https://leetcode.com/problems/valid-tic-tac-toe-state/

// My solution
class Solution {
public:
    /**
     * @brief Check current state of board meets the rules of Tic-Tac-Toe game
     * 
     * @param board Current Tic-Tac-Toe board state, for example:
     * ["XOX", " X ", "   "], ["O  ", "   ", "   "], ["XXX", "   ", "OOO"]
     * @return true Current state is valid
     * @return false Current state is invalid
     */
    bool validTicTacToe(vector<string>& board) {
        int O = 0;  // count 'O' number
        int X = 0;  // count 'X' number
        bool x_win = false;  // record X player won
        bool o_win = false;  // record O player won
        // one pass get 'O' 'X' number
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 'O') O++;
                if(board[i][j] == 'X') X++;
            }
        }
        // get who won
        for(int i = 0; i < 3; ++i){
            if(board[i] == "XXX") x_win = true;
            if(board[i] == "OOO") o_win = true;
            if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
                if(board[0][i] == 'X') x_win = true;
                if(board[0][i] == 'O') o_win = true;
            }
        }
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] ||
           board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[1][1] == 'X') x_win = true;
            if(board[1][1] == 'O') o_win = true;
        }
        
        // check current board meets all rules
        // 1. 0 =< (X - O) <= 1
        if( X - O < 0 || X - O > 1) return false;
        // 2. there is no two winner
        if(x_win && o_win) return false;
        // 3. when X win, X = O + 1
        if(x_win && X != O + 1) return false;
        // 4. when 0 win, X = O
        if(o_win && X != O) return false;
        
        return true;
    }
};