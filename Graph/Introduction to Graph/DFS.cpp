class Solution {
    private:
        void solve(vector<vector<int>>&adj, vector<int>&vis, vector<int>&ans, int starting_node){
            vis[starting_node] = 1;
            ans.push_back(starting_node);
            
            for(auto it : adj[starting_node]){
                if(!vis[it]){
                    vis[it] = 1;
                    solve(adj, vis, ans, it);
                }
            }
        }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V,0);
        vector<int>ans;
        int starting_node = 0;
        
        solve(adj, vis, ans, starting_node);
        return ans;
        
    }
};
