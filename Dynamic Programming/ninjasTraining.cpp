//memoization
int helper(int ind , int prev , vector<vector<int>> &points , int n ,
vector<vector<int>> &dp ){

    if(ind == 0 ){
        int maxi = 0 ;
        for(int i = 0 ; i < 3 ; i++ ){
            if(i != prev  ){
                maxi = max(maxi , points[0][i] ) ;
            }
        }
        return maxi;
    }
    if(dp[ind][prev] != -1 ){
        return dp[ind][prev] ;
    }

    int maxi = 0 ;
    for(int i = 0 ; i < 3 ; i++ ){
        if(i != prev ){
            int point = points[ind][i] + helper(ind-1,i,points,n,dp) ;
            maxi = max(maxi,point) ;
        }
    }

    return dp[ind][prev] = maxi ;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)) ;
    return helper(n-1,3,points,n,dp) ;
}

/********************/