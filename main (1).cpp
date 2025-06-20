#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool subsequenceSum(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    //base condition
    if(ind == n){
        if(s == sum){
            //condition satisfied
            for(auto it: ds) cout<< it << " ";
            cout<< endl;
            return true;
        }
        //condition is not satisfied
        else return false;
    }
    //take
    ds.push_back(arr[ind]);
    s+=arr[ind];
    
    if(subsequenceSum(ind+1, ds, s, sum, arr, n) == true) return true;
    ds.pop_back();
    s-=arr[ind];
    
    //not take
    if(subsequenceSum(ind+1, ds, s, sum, arr, n) == true) return true;
    else return false;
}
 
int main(){
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;
    
    vector<int> ds;
    //subsequenceSum(index, data-structure, inital-sum, sum-required, array, size)
    //The first 3 are the recursion parameter and then support for slg question
    subsequenceSum(0, ds, 0, sum, arr, n);
}