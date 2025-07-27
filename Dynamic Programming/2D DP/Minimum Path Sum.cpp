class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>prev(m, 0), curr(m, 0);

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 && j==0) curr[j] = grid[0][0];
                
                else{
                    int left = INT_MAX, up = INT_MAX;
                    if(j>0) left = grid[i][j] + curr[j-1];
                    if(i>0) up = grid[i][j] + prev[j];

                    curr[j] = min(up, left);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};
