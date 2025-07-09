class Solution {
  private:
    bool dfsCycleDetect(int node, vector<int>&vis, vector<int>&path, vector<vector<int>>&adj, vector<int>&check){
        vis[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour] && !path[neighbour]){
                if(dfsCycleDetect(neighbour, vis, path, adj, check) == true) return true;
            }
            else if(path[neighbour]){
                return true;
            }
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int V = adj.size();

        vector<int>vis(V,0);
        vector<int>path(V,0);
        vector<int>check(V,0);
        vector<int>ans;
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfsCycleDetect(i, vis, path, adj, check);
            }
        }
        
        for(int i = 0; i<V; i++){
            if(check[i] == 1) ans.push_back(i);
        }
        
        return ans;
    }
};
