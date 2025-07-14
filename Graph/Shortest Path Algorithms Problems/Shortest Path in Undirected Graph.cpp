class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        vector<int>dist(adj.size(), INT_MAX);
        
        pq.push({1,src});
        dist[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(dist[node] != INT_MAX){
                for(auto neighbour: adj[node]){
                    if(dist[neighbour] > dist[node] + 1){
                        dist[neighbour] = dist[node] + 1;
                        pq.push({dist[neighbour], neighbour});
                    }
                }
            }
        }
        
        for(int i = 0; i<adj.size(); i++){
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
        
    }
};
