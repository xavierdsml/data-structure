class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjLst(n);
        
        for(int i = 0; i<roads.size(); i++){
            adjLst[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjLst[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        // {dis, node}
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, 
        greater<pair<long long,long long>>> pq;
        vector<long long>dis(n, LLONG_MAX);
        vector<long long>ways(n, 0);
        
        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = 1e9 + 7;
        
        while(!pq.empty()){
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            
            for(auto neighbour:  adjLst[node]){
                int adjNode = neighbour.first;
                long long adjWt = neighbour.second;
                
                if(dis[adjNode] > adjWt + dist){
                    dis[adjNode] = adjWt + dist;
                    pq.push({dis[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis[adjNode] == adjWt + dist){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1] % mod;
        
    }
};
