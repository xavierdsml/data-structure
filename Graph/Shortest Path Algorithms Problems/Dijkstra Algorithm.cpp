class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //weight, node
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(V,INT_MAX);
        
        //node, weight
        vector<vector<pair<int, int>>>adjLst(V);
        for(int i = 0; i<edges.size(); i++){
            adjLst[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjLst[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        dis[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            pq.pop();
            
            for(auto neighbour: adjLst[node]){
                if(dis[neighbour.first] > dis[node] + neighbour.second){
                    dis[neighbour.first] = dis[node] + neighbour.second;
                    pq.push({dis[neighbour.first], neighbour.first});
                }
            }
        }
        return dis;
    }
};
