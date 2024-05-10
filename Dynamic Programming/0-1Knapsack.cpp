#include <bits/stdc++.h> 
int helper(int i , vector<int> weight , vector<int> value , int n , int maxWeight ,
vector<vector<int>> &dp ){

    if(i == 0 ){
        if(maxWeight >= weight[0] ){
            return value[0];
        }
        return 0 ;
    }
    // if(i < 0 ){
    //     return 0 ;
    // }

    // if(weight[i] > maxWeight ){
    //     return 0 ;
    // }

    if(dp[i][maxWeight] != -1 ){
        return dp[i][maxWeight] ;
    }

    int notPick = helper(i-1,weight,value,n,maxWeight,dp) ;
    int pick = INT_MIN ;
    if(weight[i] <= maxWeight){
     pick = helper(i-1,weight,value,n,maxWeight-weight[i] , dp) + value[i] ;
    }
    return dp[i][maxWeight] = max(pick,notPick) ;
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1)) ;
	return helper(n-1,weight,value,n,maxWeight,dp) ;
}


/********************************************TABULATION********************************8*/

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0)) ;

    for(int i = weight[0] ; i <= maxWeight ; i++ ){
        dp[0][i] = value[0] ;
    }

    for(int i = 1 ; i < n; i++ ){
        for(int j = 0 ; j <= maxWeight ; j++ ){
            int notPick = dp[i-1][j]; 
            int pick = INT_MIN ;
            if(weight[i] <= j ){
                pick = dp[i-1][j-weight[i] ] + value[i];
            }
            dp[i][j] = max(pick,notPick) ;
        }
    }
	return dp[n-1][maxWeight] ;
}



/*************************space optimized*****************/
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{


    vector<int> prev(maxWeight+1,0) ;


    for(int i = weight[0] ; i <= maxWeight ; i++ ){
        prev[i] = value[0] ;
    }

    for(int i = 1 ; i < n; i++ ){
        for(int j = maxWeight ; j >= 0 ; j-- ){
            int notPick = prev[j]; 
            int pick = INT_MIN ;
            if(weight[i] <= j ){
                pick = prev[j-weight[i] ] + value[i];
            }
            prev[j] = max(pick,notPick) ;
        }
    }
	return prev[maxWeight] ;
}