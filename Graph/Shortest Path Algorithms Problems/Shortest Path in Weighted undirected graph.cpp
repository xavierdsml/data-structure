class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adjLst(n+1);
        
        for(int i = 0; i<m; i++){
            adjLst[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjLst[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(n+1, INT_MAX);
        vector<int>parent(n+1);
        
        for(int i = 1; i<=n; i++) parent[i] = i;
        
        pq.push({0, 1});
        dist[1] = 0;
        parent[1] =1;
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            if(dist[node] != INT_MAX){
                for(auto neighbour: adjLst[node]){
                    if(dist[neighbour.first] > dist[node] + neighbour.second){
                        dist[neighbour.first] = dist[node] + neighbour.second;
                        pq.push({dist[neighbour.first], neighbour.first});
                        parent[neighbour.first] = node;
                    }
                }
            }
        }
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int>path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(node);
        reverse(path.begin(), path.end());
        
        path.insert(path.begin(), dist[n]);
        return path;
    }
};
