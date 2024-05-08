#include <bits/stdc++.h> 
/*********************MEMOIZATION********************************/
int helper(int i , int j , vector<vector<int>> &grid , vector<vector<int>> &dp){
    if(i == 0 && j == 0 ){
        return grid[0][0] ;
    }

    if(dp[i][j] != -1 ){
        return dp[i][j] ;
    }

    int up = INT_MAX ;
    if(i > 0){
        up = helper(i-1,j,grid,dp);
    }
    int left = INT_MAX ;
    if(j>0){
        left =  helper(i,j-1,grid,dp) ;
    }
    return dp[i][j] = grid[i][j] + min(up,left) ;
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    return helper(n-1,m-1,grid,dp) ;
}


/*******************TABULATION**************************/
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<vector<int>> dp(n,vector<int>(m,-1)) ;

    dp[0][0] = grid[0][0] ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            if(i==0 && j == 0 ){
                dp[0][0] =  grid[0][0] ;
            }
            else{
                int up = INT_MAX ;
                if(i > 0){
                    up = dp[i-1][j];
                }
                int left = INT_MAX ;
                if(j>0){
                    left =  dp[i][j-1] ;
                }
                dp[i][j] = grid[i][j] + min(up,left) ;
            }
        }
    }
    return dp[n-1][m-1] ;
}


/*************space optimization**********************8*/
#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size() ;
    int m = grid[0].size() ;
    vector<int> prev(m,0) ;
    vector<int> cur(m,0) ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < m ; j++ ){
            if(i==0 && j == 0 ){
                cur[0] =  grid[0][0] ;
            }
            else{
                int up = INT_MAX ;
                if(i > 0){
                    up = prev[j];
                }
                int left = INT_MAX ;
                if(j>0){
                    left = cur[j-1] ;
                }
                cur[j] = grid[i][j] + min(up,left) ;
            }
        }
        prev = cur ;
    }
    return prev[m-1] ;
}