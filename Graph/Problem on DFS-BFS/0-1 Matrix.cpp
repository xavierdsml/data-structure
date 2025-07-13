class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>vis(m, vector<int>(n, 0));
        vector<vector<int>>ans(m, vector<int>(n, 0));
        queue<pair<pair<int,int>,int>>qt;

        for(int i = 0 ; i<m; i++){
            for(int j = 0 ; j<n; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    qt.push({{i,j},0});
                }
            }
        }

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while(!qt.empty()){
            int row = qt.front().first.first;
            int col = qt.front().first.second;
            int dist = qt.front().second;

            qt.pop();
            ans[row][col] = dist;

            for(int i = 0 ; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                mat[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    qt.push({{nrow, ncol}, dist+1});
                }
            }
            
        }

        return ans;
    }
};
