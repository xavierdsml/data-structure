class Solution {
public:
    void f(int ind, int target, int k, vector<int>& ds, vector<vector<int>>& ans, vector<int>& arr){
        if(k == ds.size() && target == 0){
            ans.push_back(ds);
            return;
        }

        if(ds.size() > k) return;

        for(int i = ind; i<arr.size(); i++){
            if(arr[i] > target) break;

            ds.push_back(arr[i]);
            f(i+1, target-arr[i], k, ds, ans, arr);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr;
        vector<int>ds;
        vector<vector<int>>ans;

        for(int i = 1; i<=9; i++) arr.push_back(i);
        
        f(0, n, k, ds, ans, arr);
        return ans;
    }
};
