class Solution {
public:
    vector<vector<string> > ans; // 2D vector of strings to store the solutions
    
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));
	    solve(board, 0);
	    return ans; 
    }
    
    bool isValid(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
		    if(board[i][col] == 'Q') return false; 
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }
    
    void solve(vector<string>& board, int row) {
	    if(row == size(board)) ans.push_back(board);
        else{
            for(int col = 0; col < size(board); col++){
                if(isValid(board, row, col)) {
                    board[row][col] = 'Q';
                    solve(board, row + 1);
                    board[row][col] = '.';
                }
            }
        }
    }
};