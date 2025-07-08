class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> qt;

        int delRow[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int delCol[] = {0, +1, +1, +1, 0, -1, -1, -1};

        int islandCount = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == 'L') {
                    qt.push({row, col});
                    vis[row][col] = 1;

                    while (!qt.empty()) {
                        int r = qt.front().first;
                        int c = qt.front().second;
                        qt.pop();

                        for (int i = 0; i < 8; i++) {
                            int nrow = r + delRow[i];
                            int ncol = c + delCol[i];

                            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                                !vis[nrow][ncol] && grid[nrow][ncol] == 'L') {
                                vis[nrow][ncol] = 1;
                                qt.push({nrow, ncol});
                            }
                        }
                    }

                    islandCount++;
                }
            }
        }

        return islandCount;
    }
};
