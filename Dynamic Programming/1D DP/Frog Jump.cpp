#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    int prev2, prev1 = 0;
    int curr = 0;

    for(int i = 1; i<n; i++){
        int oneStep = prev1 + abs(heights[i] - heights[i-1]);
        int twoStep = INT_MAX;
        if(i>1) 
            twoStep = prev2 + abs(heights[i] - heights[i-2]);

        curr = min(oneStep, twoStep);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;  
}
