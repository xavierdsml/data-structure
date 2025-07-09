class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        queue<int>qt;
        vector<int>vis(V,-1);
        vector<vector<int>>adjLst(V);
        int size = edges.size();
        
        for(int i = 0; i<size; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjLst[u].push_back(v);
            adjLst[v].push_back(u);
        }
            
        qt.push(0);
        vis[0] = 0;
        
        while(!qt.empty()){
            int neighbour = qt.front();
            qt.pop();
            
            for(auto it: adjLst[neighbour]){
                if(vis[it] == -1){
                    vis[it] = !vis[neighbour];
                    qt.push(it);
                }
                
                else if (vis[it] == vis[neighbour]){
                    return false;
                }
            }
        }
        return true;
    }
};
