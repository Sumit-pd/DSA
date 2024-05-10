#include <bits/stdc++.h> 
bool helper(int ind , int k, vector<int> &arr , vector<vector<int>> &dp ){
    if(k == 0 )return 1 ;

    if(ind == 0 ) return arr[ind] == k ;

    if(dp[ind][k] != -1 ) return dp[ind][k] ;

    bool notTake = helper(ind-1,k,arr ,dp) ;

    bool take = false ;
    if (arr[ind] <= k )
    {
        take = helper(ind-1,k-arr[ind] , arr, dp ) ;
    }
    

    return dp[ind][k] = notTake || take ;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n,vector<int>(k+1,-1)) ;
    return helper(n-1,k,arr,dp) ;
}

/*****************************************TABULATION*****************************************/
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {

    vector<vector<int>> dp(n,vector<int>(k+1,0)) ;
    if(arr[0]<=k){
        dp[0][arr[0]] = 1;
    }
    for(int i = 0 ; i < n; i++ ){
        dp[i][0] = 1 ;
    }
    for(int i = 1 ; i < n; i++ ){
        for(int j = 1 ; j <= k ; j++ ){
            bool notTake = dp[i-1][j] ;

            bool take = false ;
            if (arr[i] <= j )
            {
                take = dp[i-1][j-arr[i] ] ;
            }

            dp[i][j] = notTake || take ;
        }
    }
    return dp[n-1][k] ;
}
