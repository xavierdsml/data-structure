#include<bits/stdc++.h>
using namespace std;

void reversedArray(vector<int> &arr, int l, int r){
    //base condition
    if(l >= r) return;
    
    swap(arr[l], arr[r]);
    return reversedArray(arr, l+1, r-1);
    
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    reversedArray(arr, 0, arr.size() - 1);
    for(auto it: arr) cout<<it <<" ";
}
