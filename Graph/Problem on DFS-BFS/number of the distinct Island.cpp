class Solution {
  private:
    void dfs(int row, int col, 
    vector<vector<int>>&vis, vector<vector<int>> &grid, vector<pair<int, int>> &vect, 
    int brow, int bcol, int delRow[], int delCol[]){
        vis[row][col] = 1;
        
        vect.push_back({brow - row, bcol - col});
        
        for(int i = 0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size()
            && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid, vect, brow, bcol, delRow, delCol);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        set<vector<pair<int,int>>>st;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>>vect;
                    dfs(i, j, vis, grid, vect, i, j, delRow, delCol);
                    st.insert(vect);
                }
            }
        }
        return st.size();
    }
};
