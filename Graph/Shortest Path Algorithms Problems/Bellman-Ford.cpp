class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int>dis(V, INT_MAX);
        dis[src] = 0;
        
        for(int i = 0; i<V-1; i++){
            for(auto neighbour: edges){
                int u = neighbour[0];
                int v = neighbour[1];
                int wt = neighbour[2];
                
                if(dis[u] != INT_MAX && dis[u] + wt < dis[v]){
                    dis[v] = dis[u] + wt;
                }
            }
        }
        
        for(auto neighbour: edges){
            int u = neighbour[0];
            int v = neighbour[1];
            int wt = neighbour[2];
            
            if(dis[u] != INT_MAX && dis[u] + wt < dis[v]) return {-1};
        }
        
        for(int i = 0; i<V; i++) if(dis[i] == INT_MAX) dis[i] = 1e8;
        return dis;
    }
};
