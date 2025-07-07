class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //define a matrix
        vector<vector<int>>vis(n, vector<int>(m,0));
        //{{r,c},time}
        queue<pair<pair<int,int>,int>>qt;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    qt.push({{i,j},0});
                }
            }
        }

        int t = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        while(!qt.empty()){
            int r = qt.front().first.first;
            int c = qt.front().first.second;
            int time = qt.front().second;

            t = max(t, time);

            qt.pop();

            for(int i = 0; i<4; i++){
                int nRow = r + drow[i];
                int nCol = c + dcol[i];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol] == 1 && 
                vis[nRow][nCol] != 2){
                    qt.push({{nRow, nCol},time+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }

        //now we have to check all 1 is converted in to 2 or not 
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] !=2 && grid[i][j] == 1) return -1;
            }
        }
        return t;
    }
};
