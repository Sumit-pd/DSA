// recursion
int helper(int ind , vector<int> houses , int n ){
    if(ind < 0 ){
        return 0 ;
    }

    int pick = helper(ind - 2 , houses , n) + houses[ind] ;
    int notPick = helper(ind-1 , houses,n) ;
    return max(pick,notPick) ;
}
int maxMoneyLooted(vector<int> &houses, int n)
{
	return helper(n-1,houses,n) ;
}

//memoization
int helper(int ind , vector<int> houses , int n, vector<int> &dp ){
    if(ind < 0 ){
        return 0 ;
    }

    if(dp[ind] != -1 ){
        return dp[ind] ;
    }

    int pick = helper(ind - 2 , houses , n , dp) + houses[ind] ;
    int notPick = helper(ind-1 , houses,n,dp) ;
    return dp[ind] = max(pick,notPick) ;
}
int maxMoneyLooted(vector<int> &houses, int n)
{

    vector<int> dp(n,-1) ;
	return helper(n-1,houses,n,dp) ;
}


/***********************************************************************************************/


//tabulation

int maxMoneyLooted(vector<int> &houses, int n)
{

    vector<int> dp(n+1,-1) ;
    dp[0] = houses[0] ;
    int neg = 0 ;
    for(int i = 1 ; i < n; i++ ){
        int pick ;
        if(i == 1 ){
            pick = houses[i] + neg ;
        }
        else{
            pick  = houses[i] + dp[i-2] ; 
        }
        int notPick = dp[i-1] ;
        dp[i] = max(pick,notPick) ;
    }
	return dp[n-1] ;
}




/**********************************************************************************/
//space optimization

int maxMoneyLooted(vector<int> &houses, int n)
{
    int prev2 = 0 ;
    int prev = houses[0] ;
    for(int i = 1 ; i < n; i++ ){
        int pick = houses[i] + prev2 ;
        int notPick = prev ;
        prev2 = prev ;
        int cur = max(pick,notPick) ;
        prev = cur ;
    }

    return prev;
}