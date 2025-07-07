class Solution {
  private:
    void dfs(vector<vector<int>>&adjLst, int node, vector<int>&temp, vector<int>&vis){
        vis[node] = 1;
        temp.push_back(node);
        
        for(auto it: adjLst[node]){
            if(!vis[it]){
                dfs(adjLst, it, temp, vis);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adjLst(V);
        int edgeSize = edges.size();
        
        for(int i = 0; i<edgeSize; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjLst[u].push_back(v);
            adjLst[v].push_back(u);
        }
        
        vector<int>vis(V,0);
        vector<vector<int>>ans;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                vector<int>temp;
                dfs(adjLst, i, temp, vis);
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
