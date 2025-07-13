class Solution {
  private:
    bool bfs(int node, vector<vector<int>>&adjLst, vector<int>&vis){
        queue<pair<int,int>>qt;
        qt.push({node,-1});
        vis[node] = 1;
      
        
        while(!qt.empty()){
            int node = qt.front().first;
            int parent = qt.front().second;
            qt.pop();
            
            for(auto neighbour: adjLst[node]){
                if(!vis[neighbour]){
                    qt.push({neighbour, node});
                    vis[neighbour] = 1;
                }
                else if(neighbour != parent) return true;
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adjLst(V);
        vector<int>vis(V,0);
        
        for(int i = 0; i<edges.size(); i++){
            adjLst[edges[i][0]].push_back(edges[i][1]);
            adjLst[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                if(bfs(i, adjLst, vis)) return true;
            }
        }
        return false;
    }
};
