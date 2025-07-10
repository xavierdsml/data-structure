#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<vector<int>>adjLst(v);
    vector<int>inDegree(v,0);

    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjLst[u].push_back(v);
        inDegree[v]++;
    }

    queue<int>qt;
    for(int i = 0; i<v; i++){
        if(inDegree[i] == 0) qt.push(i);
    }

    vector<int>ans;
    while(!qt.empty()){
        int node = qt.front();
        ans.push_back(node);
        qt.pop();

        for(auto it: adjLst[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) qt.push(it);
        }
    }

    return ans;
}
