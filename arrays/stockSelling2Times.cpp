
//recursion way
//this trick will work on any limit given in the question
#include<bits/stdc++.h>
int helper(vector<int> &values , int n , int ind , int buy , vector< vector<vector<int>> > &dp , int limit){
    if(ind == n ){
        return 0 ;
        //we exausted the array so no profits to be made
    }
    if(limit == 0){
        return 0 ;
    }

    if(dp[ind][buy][limit] != -1 ){
        return dp[ind][buy][limit] ;
    }
    if(buy){
        int WeBuy = helper(values,n,ind+1,0,dp,limit) - values[ind] ;
        int weDoNot = helper(values,n,ind+1,1,dp,limit) ;
        return dp[ind][buy][limit] = max( WeBuy , weDoNot  ) ;
    }
    else{
        return dp[ind][buy][limit] = max(helper(values,n,ind+1,1,dp,limit-1)+values[ind],helper(values,n,ind+1,0,dp,limit)) ;
    }
}
int maxProfit(vector<int>& prices)
{
    int n = prices.size() ;
    vector< vector<vector<int>> > dp(n, vector<vector<int>>(2,vector<int>(3,-1))) ;
    return helper(prices,n,0,1,dp,2) ;
}



/******************************************************************************************/
int maxProfit(vector<int>& prices)
{
    int n = prices.size() ;
    vector<int> profit(n,0) ;
    int maxPrice = prices[n-1] ;
    for(int i = n-2 ; i >= 0 ; i-- ){
        if(prices[i] > maxPrice){
            //checking if the array got any higher price
            //this idea is to sell at the maximum price
            maxPrice = prices[i];
        }
        profit[i] = max(profit[i+1],maxPrice - prices[i]) ;
    }

    int minPrice = prices[0] ;
    for(int i = 1 ; i < n ; i++ ){
        if(prices[i] < minPrice){
            //checking if the array got any lower price 
            //the idea to is to buy at the lowest price
            minPrice = prices[i] ;
        }
        profit[i] = max(profit[i-1],profit[i] +( prices[i] - minPrice));
    }
    return profit[n-1] ;
}
