class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        util(board, ans, 0, n);
        return ans;
    }

    void util(vector<string> &board, vector<vector<string>> &ans, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(isValid(board, row, i, n)){
                board[row][i] = 'Q';
                util(board, ans, row+1, n);
                board[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string> &board, int row, int col, int n){
        for(int i=row; i>=0; i--)
            if(board[i][col] == 'Q') return false;
        
        for(int i=row, j=col; i>=0 && j>=0; i--,j--)
           if(board[i][j] == 'Q') return false;
        
        for(int i=row, j=col; i>=0 && j<n; i--,j++)
           if(board[i][j] == 'Q') return false;

        return true;        
    }
};