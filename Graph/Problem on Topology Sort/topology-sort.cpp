class Solution {
  private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adjLst, stack<int>&st){
        vis[node] = 1;
        
        for(auto neighbour : adjLst[node]){
            if(!vis[neighbour]){
                dfs(neighbour, vis, adjLst, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>vis(V,0);
        vector<int>ans;
        stack<int>st;
        vector<vector<int>>adjLst(V);
        
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjLst[u].push_back(v);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adjLst, st);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
