class Solution {
  public:
    bool dfs(int node, int parent, vector<vector<int>>&adjLst, vector<int>&vis){
        vis[node] = 1;
        
        for(auto neighbour: adjLst[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour, node, adjLst, vis)) return true;
            }
            else if(neighbour != parent) return true;
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        //using the dfs approch
        
        vector<vector<int>>adjLst(V);
        vector<int>vis(V,0);
        
        for(int i = 0; i<edges.size(); i++){
            adjLst[edges[i][0]].push_back(edges[i][1]);
            adjLst[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, adjLst, vis)) return true;
            }
        }
        
        return false;
    }
};
