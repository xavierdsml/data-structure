class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;

        solve(0, temp, ans, candidates, target);
        return ans;
    }


 private:
    void solve(int index, vector<int>&temp, vector<vector<int>>&ans, vector<int>&candidates, int target){

        //base condition 
        if(index == candidates.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }

        if(candidates[index] <= target){
            temp.push_back(candidates[index]);
            solve(index, temp, ans, candidates, target-candidates[index]);
            temp.pop_back();
        }
        solve(index+1, temp, ans, candidates, target);
    }
};
