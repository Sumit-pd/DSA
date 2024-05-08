#include <bits/stdc++.h> 
int helper(int ind , vector<int> heights , vector<int> &dp ){
    if(ind == 0 ){
        return 0 ;
    }
    if(dp[ind] != -1 ){
        return dp[ind] ;
    }
    int i = ind ;
    int left = helper(ind-1 , heights,dp) + abs(heights[i] - heights[i-1]) ;
    int right = INT_MAX ;
    if(ind >1 ){
        right = helper(ind-2 , heights,dp) + abs(heights[i] - heights[i-2]) ;
    }
    return dp[ind] = min(left,right) ;
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1) ;
    return helper(n-1,heights,dp) ;
}





//tabulation
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1) ;
    dp[0] = 0 ;
    for(int i = 1 ; i < n ; i++ ){
        int left = dp[i-1]  + abs(heights[i] - heights[i-1]) ;
       int right = INT_MAX ;
        if(i >1 ){
            right = dp[i-2] + abs(heights[i] - heights[i-2]) ;
        }
        dp[i] = min(left,right) ;
    }
    return dp[n-1] ;
}