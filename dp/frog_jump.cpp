#include <bits/stdc++.h> 
using namespace std;

// int solve(int n,vector<int> &heights,vector<int> &dp){
//     if(n == 0) return 0;

//     if(dp[n] != -1) return dp[n];

//     int left = solve(n-1,heights,dp) + abs(heights[n] - heights[n-1]);
//     int right = INT_MAX;
//     if(n>1)right = solve(n-2,heights,dp) + abs(heights[n] - heights[n-2]);

//     return dp[n] = min(left,right);
// }
int frogJump(int n, vector<int> &heights){

    int prev = 0;
    int prev1 = 0;

    for(int i = 1;i<n;i++){
        int left = prev + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if(i > 1) right = prev1 + abs(heights[i] - heights[i-2]);
        // int curr = min(left,right);
        prev1 = prev;
        prev = min(left,right);
    }

    // return solve(n-1,heights,dp);
    return prev;
}