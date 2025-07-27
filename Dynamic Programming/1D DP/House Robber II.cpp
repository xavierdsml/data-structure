#include <bits/stdc++.h> 

long long int f(int i, vector<int>& valueInHouse, vector<long long int> &dp){
    if(i<0) return 0;
    if(i == 0) return valueInHouse[0];

    if(dp[i] != -1) return dp[i];
    long long int pick =  valueInHouse[i] + f(i-2, valueInHouse, dp);
    long long int notPick = f(i-1, valueInHouse, dp);

    return dp[i] = max(pick, notPick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();

    if(n==0) return 0;
    if(n==1) return valueInHouse[0];

    vector<int>temp1(valueInHouse.begin()+1, valueInHouse.end());
    vector<int>temp2(valueInHouse.begin(), valueInHouse.end()-1);    

    vector<long long int>dp1(temp1.size()+1, -1), dp2(temp2.size()+1, -1);
    long long int a = f(temp1.size()-1, temp1, dp1);
    long long int b = f(temp2.size()-1, temp2, dp2);

    return max(a, b);
}
