class Solution {
  private:
    void dfs(int node, vector<vector<pair<int,int>>> &adjLst, vector<int> &vis, 
    stack<int> &st){
        vis[node] = 1;
        
        for(auto neighbour: adjLst[node]){
            int curr = neighbour.first;
            if(!vis[curr]){
                dfs(curr, adjLst, vis, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adjLst(V);
        
        for(int i = 0; i<E; i++){
            adjLst[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        stack<int>st;
        vector<int>vis(V, 0);
        
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i, adjLst, vis, st);
            }
        }
        
        vector<int>dis(V, INT_MAX);
        dis[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(dis[node] != INT_MAX){
                for(auto neighbour: adjLst[node]){
                    if(dis[neighbour.first] > dis[node] + neighbour.second){
                        dis[neighbour.first] = dis[node] + neighbour.second;
                    }
                }
            }
            
        }
        
        for(int i = 0; i<dis.size(); i++){
            if(dis[i] == INT_MAX) dis[i] = -1;
        }
        
        return dis;
    }
};
