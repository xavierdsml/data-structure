class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid, int delRow[], int delCol[]){
        vis[row][col] = 1;

        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() &&
            grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid, delRow, delCol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i = 0; i<grid[0].size(); i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0, i, vis, grid, delRow, delCol);
            }
            if(grid[grid.size()-1][i] == 1 && !vis[grid.size()-1][i]){
                dfs(grid.size()-1, i, vis, grid, delRow, delCol);
            }
        }

        for(int i = 0; i<grid.size(); i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, vis, grid, delRow, delCol);
            }
            if(grid[i][grid[0].size()-1] == 1 && !vis[i][grid[0].size()-1]){
                dfs(i, grid[0].size()-1, vis, grid, delRow, delCol);
            }
        }

        int cnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
