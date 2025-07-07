class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        
        vector<vector<int>>adjLst(V); //zero-based indexing 
        int edgeSize = edges.size();
        
        for(int i = 0; i<edgeSize; i++){
                
                int u = edges[i].first;
                int v = edges[i].second;
            
                adjLst[u].push_back(v);
                adjLst[v].push_back(u);
        }
        return adjLst;
    }
};
