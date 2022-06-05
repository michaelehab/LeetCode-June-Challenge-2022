class Solution {
public:
    int total = 0;
    
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
	    solve(board, 0);
        return total;
    }
    
    bool isValid(vector<string>& board, int row, int col) {
	    for(int i = 0; i < board.size(); i++) {
		    if(board[i][col] == 'Q') return false; 
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  board.size() && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }
    
    void solve(vector<string>& board, int row) {
	    if(row == board.size()) total++;
        else{
            for(int col = 0; col < board.size(); col++){
                if(isValid(board, row, col)) {
                    board[row][col] = 'Q';
                    solve(board, row + 1);
                    board[row][col] = '.';
                }
            }
        }
    }
};