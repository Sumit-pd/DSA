#include<bits/stdc++.h>
/*****************************MEMOIZATION************************************/
long helper(int i , int value , int * denominations , vector<vector<int>> &dp  ){
    if(i == 0 ){
        return value % denominations[0] == 0  ;
    }

    if(dp[i][value] != -1 ){
        return dp[i][value] ;
    }

    int notPick = helper(i-1,value,denominations,dp) ;
    int pick = 0 ;
    if(denominations[i] <= value ){
        pick = helper(i,value-denominations[i],denominations,dp) ;
    }
    return dp[i][value] = notPick+pick ;
}
/*******************TABULATION******************************/
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<int>> dp(n,vector<int>(value+1,0)) ;

    for(int i = 0 ; i <= value ; i++ ){
        dp[0][i] = i % denominations[0] == 0;
    }

    for(int i = 1 ; i < n ; i++ ){
        for(int j = 0 ; j <= value ; j++ ){
            int notPick =dp[i-1][j] ;
            int pick = 0 ;
            if(denominations[i] <= j ){
                pick =dp[i][j-denominations[i] ] ;
            }
            dp[i][j] = notPick + pick ;
        }
    }
    return dp[n-1][value] ;
}

/********************************SPACE OPMIZATION***********************/
long countWaysToMakeChange(int *denominations, int n, int value)
{

    vector<int> prev(value+1,0) ;

    for(int i = 0 ; i <= value ; i++ ){
        prev[i] = i % denominations[0] == 0 ;
    }

    for(int i = 1 ; i < n ; i++ ){
        vector<int> cur(value+1,0) ;
        for(int j = 0 ; j <= value ; j++ ){
            int notPick =prev[j] ;
            int pick = 0 ;
            if(denominations[i] <= j ){
                pick =cur[j-denominations[i] ] ;
            }
            cur[j] = notPick + pick ;
        }
        prev = cur ;
    }
    return prev[value] ;
}