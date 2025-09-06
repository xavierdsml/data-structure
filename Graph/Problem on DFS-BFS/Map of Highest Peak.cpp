class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> vis(isWater.size(), vector<int>(isWater[0].size(), 0));
        queue<pair<int, pair<int,int>>> qt;

        for(int i = 0; i<isWater.size(); i++){
            for(int j = 0; j<isWater[0].size(); j++){
                if(isWater[i][j] == 1){
                    qt.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, +1, 0, -1};
        while(!qt.empty()){
            int dist = qt.front().first;
            int row = qt.front().second.first;
            int col = qt.front().second.second;
            qt.pop();

            isWater[row][col] = dist;

            for(int i = 0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && nrow<isWater.size() && ncol>=0 
                && ncol<isWater[0].size() && !vis[nrow][ncol] && isWater[nrow][ncol] == 0){
                    qt.push({dist+1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return isWater;
    }
};
