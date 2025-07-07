class Solution {
  private:
   vector<int> Trav(vector<vector<int>>&adj, int V, vector<int>&ans){
       vector<int> vis(V, 0);
       
       queue<int>qt;
       qt.push(0);
       vis[0] = 1;
       while(!qt.empty()){
           int node = qt.front();
           qt.pop();
           ans.push_back(node);
           
           for(auto it:adj[node]){
               if(!vis[it]){
                   vis[it] = 1;
                   qt.push(it);
               }
           }
       }
       return ans;
    }
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>ans;
        int V = adj.size();
        
        return Trav(adj, V, ans);
        
    }
};
