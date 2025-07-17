class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int>vis(V,0);
        int wtCount = 0;
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(vis[node]) continue;
            vis[node] = 1;
            wtCount += wt;
            
            for(auto neighbour: adj[node]){
                if(!vis[neighbour[0]]){
                    pq.push({neighbour[1], neighbour[0]});
                }
            }
        }
        return wtCount;
        
    }
};
