class Solution {
  private:
    bool dfs(int node, vector<int>&vis, vector<vector<int>>&adjLst){
        
        for(auto neighbour : adjLst[node]){
            if(vis[neighbour] == -1){
                vis[neighbour] = !vis[node];
                if(dfs(neighbour, vis, adjLst)==false) return false;
            }
            else if(vis[neighbour] == vis[node]) return false;
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        vector<int>vis(V,-1);
        vector<vector<int>>adjLst(V);
        
        int size = edges.size();
        for(int i = 0; i<size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjLst[u].push_back(v);
            adjLst[v].push_back(u);
        }
        
        for(int i = 0; i<V; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                if(dfs(i, vis, adjLst)==false) return false;
            }
        }
        
        return true;
        
    }
};
