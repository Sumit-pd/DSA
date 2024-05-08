/***********************MEMOIZATION*****************************************/
#include <bits/stdc++.h> 
int helper(int i , int j , int n , int m, vector<vector<int>> &dp ){
    if(i < 0 || j < 0 ){
        return 0 ;
    }

    if(i == 0 && j == 0 ){
        return 1 ;
    }

    if(dp[i][j] != -1 ){
        return dp[i][j] ;
    }
    int down = helper(i-1,j,n,m,dp) ;
    int right = helper(i,j-1,n,m,dp) ;

    return dp[i][j] = down + right ;
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1)) ;
	return helper(m-1,n-1,m,n,dp) ;
}



/**************************TABULATION*************************/

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1)) ;
    
	for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if(i == 0 && j == 0 ){
                dp[i][j] = 1 ;
            }
            else{
                int top = 0  ;
                if(i > 0){
                    top = dp[i-1][j] ;
                }
                int left = 0 ;
                if(j > 0 ){
                    left = dp[i][j-1] ;
                }
                dp[i][j] = top + left ;
            }
        }
    }
    return dp[m-1][n-1] ;
}




/************************SPACE OPMIZATION*********************************/


#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
    vector<int> cur(n,-1) ;
    vector<int> prev(n,-1) ;
    
	for(int i = 0 ; i < m ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if(i == 0 && j == 0 ){
                cur[j] = 1 ;
            }
            else{
                int top = 0  ;
                if(i > 0){
                    top = prev[j] ;
                }
                int left = 0 ;
                if(j > 0 ){
                    left = cur[j-1] ;
                }
                cur[j] = top + left ;
            }
        }
        prev = cur ;
    }
    return prev[n-1] ;
}