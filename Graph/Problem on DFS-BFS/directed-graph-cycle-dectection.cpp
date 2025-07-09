class Solution {
  private:
    bool dfsCycleDetect(int node, vector<int>&vis, vector<int>&path, vector<vector<int>>&adjLst){
        vis[node] = 1;
        path[node] = 1;
        
        for(auto neighbour : adjLst[node]){
            if(!vis[neighbour] && !path[neighbour]){
                if(dfsCycleDetect(neighbour, vis, path, adjLst) == true) return true;
            }
            else if(path[neighbour]) return true;
        }
        path[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>>adjLst(V);
        vector<int>vis(V,0);
        vector<int>path(V,0);
        
        int size = edges.size();
        
        for(int i=0; i<size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjLst[u].push_back(v);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i] && !path[i]){
                if(dfsCycleDetect(i, vis, path, adjLst) == true) return true;
            }
        }
        
        return false;
    }
};
