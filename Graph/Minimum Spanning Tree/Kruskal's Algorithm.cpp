class DisjointSet{
public:
    vector<int>parent, rank, size;
    
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        
        for(int i = 0; i<=n; i++) parent[i] = i;
    }
    
    int findUpar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUpar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>>adjLst;
        
        for(int i = 0; i<edges.size(); i++){
            adjLst.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
        }
        
        sort(adjLst.begin(),adjLst.end());
        DisjointSet ds(V);
        
        int wCount = 0;
        for(auto edge: adjLst){
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if(ds.findUpar(u) != ds.findUpar(v)){
                wCount += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return wCount;
    }
};
