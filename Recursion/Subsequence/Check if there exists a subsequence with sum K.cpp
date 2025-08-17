class Solution {
public:
    bool f(int ind, int target, vector<int> &arr){
        if(ind == arr.size()) return(target == 0);
        
        
        if(target>=arr[ind])
            if(f(ind+1, target-arr[ind], arr)) return true;
        
        if(f(ind+1, target, arr)) return true;
        
        return false;
    }
public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return f(0, k, arr);
    }
};
