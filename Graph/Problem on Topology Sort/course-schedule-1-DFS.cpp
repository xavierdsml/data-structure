class Solution {
private:
    bool dfs(int node, vector<int>&vis, vector<int>&path, vector<vector<int>>&adjLst){
        vis[node] = 1;
        path[node] = 1;

        for(auto neighbour: adjLst[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour, vis, path, adjLst)==false) return false;
            }
            else if(path[neighbour]) return false;
        }
        path[node] = 0;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjLst(numCourses);
        vector<int>vis(numCourses,0), path(numCourses, 0);

        for(int i = 0; i<prerequisites.size(); i ++){
            adjLst[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i<numCourses; i++){
            if(dfs(i, vis, path, adjLst)==false) return false;
        }

        return true;
    }
};
