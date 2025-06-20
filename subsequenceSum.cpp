#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void subsequenceSum(int ind, vector<int> &ds, int s, int sum, int arr[], int n){
    //base case
    if(ind == n){ //means we are at last index 
        if(s == sum){ // the required sum and the summiation sum is same then priting the data-structure
            for(auto it : ds) cout<< it << " ";
            cout << endl;
        }
        return;
    }
    //take or not take
    ds.push_back(arr[ind]); //add krege data-structure mai 
    s+=arr[ind];
    
    subsequenceSum(ind+1, ds, s, sum, arr, n);
    ds.pop_back(); //when you comeback not take wala (remove krna)
    s-=arr[ind];
    
    //not take
    subsequenceSum(ind+1, ds, s, sum, arr, n);
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