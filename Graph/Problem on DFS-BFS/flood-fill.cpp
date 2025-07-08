class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>ans = image;
        queue<pair<int,int>>qt;

        int startColour = image[sr][sc];

        if(startColour == color) return image;

        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        qt.push({sr,sc});
        vis[sr][sc] = 1;

        while(!qt.empty()){
            int row = qt.front().first;
            int col = qt.front().second;
            qt.pop();

            ans[row][col] = color;

            for(int i = 0; i<4; i++){
                int nrow = row + dRow[i];
                int ncol = col + dCol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && 
                image[nrow][ncol] == startColour){
                    vis[nrow][ncol] = 1;
                    qt.push({nrow, ncol});
                }
            }
        }
        return ans;
    }
};
