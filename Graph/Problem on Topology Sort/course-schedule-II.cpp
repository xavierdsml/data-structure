class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjLst(numCourses);
        vector<int>inDegree(numCourses,0);
        vector<int>ans;
        queue<int>qt;

        for(int i = 0; i<prerequisites.size(); i++){
            adjLst[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }

        for(int i = 0; i<numCourses; i++){
            if(inDegree[i] == 0) qt.push(i);
        }


        while(!qt.empty()){
            int node = qt.front();
            ans.push_back(node);
            qt.pop();

            for(auto neighbour: adjLst[node]){
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0) qt.push(neighbour);
            }
        }

        if(ans.size() != numCourses) return {};
        return ans;
    }
};
