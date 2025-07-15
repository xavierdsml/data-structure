class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<vector<pair<int,int>>>adjLst(n);
        
        for(int i = 0; i<flights.size(); i++){
            adjLst[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        // {steps, {node, dist}}
        queue<pair<int,pair<int,int>>>qt;
        vector<int>dis(n, INT_MAX);
        
        dis[src] = 0;
        qt.push({0, {src, 0}});
        
        while(!qt.empty()){
            int steps = qt.front().first;
            int node = qt.front().second.first;
            int dist = qt.front().second.second;
            qt.pop();
            
            if(steps > K) continue;
            for(auto neighbour: adjLst[node]){
                int adjNode = neighbour.first;
                int adjWeight = neighbour.second;
                
                if(dis[adjNode] > dist + adjWeight && steps<=K){
                    dis[adjNode] = dist + adjWeight;
                    qt.push({steps+1, {adjNode, dis[adjNode]}});
                }
            }
        }
        
        if(dis[dst] == INT_MAX) return -1;
        return dis[dst];
        
    }
};
