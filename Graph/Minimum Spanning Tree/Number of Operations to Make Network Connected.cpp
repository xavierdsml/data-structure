class DisjointSet {
public:
    vector<int>parent, size, rank;

    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++) parent[i] = i;
    }

    int findUpar(int node) {
        if(node == parent[node]) return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_v] > rank[ulp_u]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges = 0;

        for(auto neighbour: connections){
            int u = neighbour[0];
            int v = neighbour[1];

            if(ds.findUpar(u) != ds.findUpar(v)){
                ds.unionBySize(u,v);
            }
            else extraEdges++;
        }

        int computer = 0;
        for(int i = 0; i<n; i++){
            if(ds.parent[i] == i) computer++;
        }

        int requiredEdges = computer - 1;
        if(extraEdges >= requiredEdges) return requiredEdges;
        else return -1;
    }
};
