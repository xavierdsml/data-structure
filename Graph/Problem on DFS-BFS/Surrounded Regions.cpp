class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&board, int delRow[], int delCol[]){
        vis[row][col] = 1;

        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<board.size() && ncol>=0 && ncol<board[0].size() &&
            board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, board, delRow, delCol);
            }
        }

    }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(), vector<int>(board[0].size(), 0));
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        //checking for the first and the last row
        for(int i = 0; i<board[0].size(); i++){
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, vis, board, delRow, delCol);
            }
            if(board[board.size()-1][i] == 'O' && !vis[board.size()-1][i]){
                dfs(board.size()-1, i, vis, board, delRow, delCol);
            }
        }

        //checking for the first and the last col
        for(int i = 0; i<board.size(); i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, vis, board, delRow, delCol);
            }
            if(board[i][board[0].size()-1] == 'O' && !vis[i][board[0].size()-1]){
                dfs(i, board[0].size()-1, vis, board, delRow, delCol);
            }
        }

        //traverse in the board and converted all 'X' to 'O' inside the bounndary
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] ='X';
            }
        }
    }
};
