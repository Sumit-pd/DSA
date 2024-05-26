//memoization
#include<vector>
long helper(long * values , int n , int ind , int buy ,vector<vector<long>> &dp){
    if(ind == n ){
        return 0 ;
        //we exausted the array so no profits to be made
    }
    if(dp[ind][buy] != -1 ){
        return dp[ind][buy] ;
    }
    if(buy){
        long WeBuy = helper(values,n,ind+1,0,dp) - values[ind] ;
        long weDoNot = helper(values,n,ind+1,1,dp) ;
        return dp[ind][buy] = max( WeBuy , weDoNot  ) ;
    }
    else{
        return dp[ind][buy] = max(helper(values,n,ind+1,1,dp)+values[ind],helper(values,n,ind+1,0,dp)) ;
    }
}
long getMaximumProfit(long *values, int n)
{

    vector<vector<long>> dp(n,vector<long>(2,-1)) ;
    return helper(values,n,0,1,dp) ;
}

//tabulation

long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0)) ;
    for(int ind = n-1 ; ind >= 0 ; ind-- ){
        for(int buy = 0 ; buy < 2 ; buy++ ){
            if(buy){
                long WeBuy =dp[ind+1][0] - values[ind] ;
                long weDoNot = dp[ind+1][1] ;
                dp[ind][buy] = max( WeBuy , weDoNot  ) ;
            }
            else{
                dp[ind][buy] = max(dp[ind+1][1] +values[ind], dp[ind+1][0] ) ;
            }
        }
    }
    return dp[0][1] ;
}



/******************space optimized*****************/

long getMaximumProfit(long *values, int n)
{
    // vector<vector<long>> dp(n+1,vector<long>(2,0)) ;
    vector<long> next(2,0);
    for(int ind = n-1 ; ind >= 0 ; ind-- ){
        vector<long> cur(2,0) ;
        for(int buy = 0 ; buy < 2 ; buy++ ){
            if(buy){
                long WeBuy =next[0] - values[ind] ;
                long weDoNot = next[1] ;
                cur[buy] = max( WeBuy , weDoNot  ) ;
            }
            else{
                cur[buy] = max(next[1] +values[ind], next[0] ) ;
            }
        }
        next = cur ;
    }
    return next[1] ;
}