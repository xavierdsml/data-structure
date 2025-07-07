class Solution {
private:
 void dfs(vector<vector<int>>&adjLst, int node, vector<int>&vis){
    vis[node] = 1;

    for(auto it: adjLst[node]){
        if(!vis[it]){
            dfs(adjLst, it, vis);
        }
    }
 }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjLst(n);

        //create the adjcencyList from the adjcencyMatrix
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjLst[i].push_back(j);
                    adjLst[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(adjLst, i, vis);
            }
        }

        return cnt;
    }
};
