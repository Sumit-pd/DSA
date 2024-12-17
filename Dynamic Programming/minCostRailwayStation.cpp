#include<bits/stdc++.h>
using namespace std ;
int minCost(int n, vector<vector<int>> &cost){
    // we are actually calculation the cost to reach n from 0 
    if(n == 0){
        return 0 ; 
        // the value to go from 0 to 0 will be 0 
    }
    if(n == 1){
        // this will be going from 0 to 1 
        return cost[0][1] ;
    }
    int ans = INT_MAX ;
    for(int k = 0 ; k <= n ; k++ ){
        int smallCost = minCost(k,cost) + cost[k][n] ;
        ans = min(ans,smallCost) ;
    }
    return ans ;
}

int minCost(int n, vector<vector<int>> &cost){
    
    vector<int> dp(n+1,0) ;
    dp[1] = cost[0][1] ;
    for(int i = 2 ; i <= n ; i++ ){
        int ans = INT_MAX ;
        for(int k = 0 ; k <= n ; k++ ){
            int smallCost = dp[k] + cost[k][i] ;
            ans = min(ans,smallCost) ;
        }
        dp[i] = ans ;
    }
    return dp[n] ;
}



int minCost(int n )