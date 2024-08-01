int cutRod(vector<int> &price, int n, int ind)
{
    if (ind == 0)
    {
        return n * price[0] ;
    }
    
    int notTake = cutRod(price,n,ind-1) ;

    int take = -1e9 ;
    int rodLength = ind+1 ; // the index starts from 1 
    if(n >= rodLength){
        // the we can cut the rod
        take = cutRod(price,n-rodLength,ind) + price[ind];
    }
    return max(notTake,take) ;

}


//memoization

int helper(int ind ,vector<int> &price , int n, vector<vector<int>> cache){
	if(ind == 0){
		return n * price[0] ;
	}
	if(cache[ind][n] != -1){
		return cache[ind][n] ;
	}
	int notTake = helper(ind-1,price,n,cache) ;
	int take = INT_MIN ;
	if(ind+1 <= n){
		take = helper(ind,price,n-ind-1,cache) + price[ind] ;
	}
	return cache[ind][n] = max(take,notTake) ;
}
int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> cache(price.size(),vector<int>(n+1,-1)) ;
	return helper(price.size() - 1 , price,n,cache) ;
}


// tabulation

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(),vector<int>(n+1,-1)) ;

	for(int i = 0 ; i <= n ; i++ ){
		dp[0][i] = i * price[0] ;
	}
	for(int i = 1 ; i < n ; i++ ){
		for(int j = 0 ; j <= n ; j++){
			// here j is the different lengths of the rod
			int notTake = dp[i-1][j] ;
			int take = -1e9 ;
			if(j >= i+1 ){
                int rodSize = i + 1 ;
				take  = dp[i][j-rodSize] + price[i] ;
			}
			dp[i][j] = max(take,notTake) ;
		}
	}
	return dp[n-1][n] ;
}

// space optimization

int cutRod2(vector<int> &price, int n)
{
	vector<vector<int>> dp(price.size(),vector<int>(n+1,-1)) ;
    vector<int> prev(n+1,-1) ;
	vector<int> cur(n+1,-1) ;

	for(int i = 0 ; i <= n ; i++ ){
		dp[0][i] = i * price[0] ;
		prev[i] = i * price[0] ;
		cur[i] = i * price[0] ;
	}
	for(int i = 1 ; i < n ; i++ ){
		for(int j = 0 ; j <= n ; j++){
			// here j is the different lengths of the rod
			int notTake = prev[j] ;
			int take = -1e9 ;
			if(j >= i+1 ){
                int rodSize = i + 1 ;
				take  = cur[j-rodSize] + price[i] ;
			}
			cur[j] = max(take,notTake) ;
		}
		prev = cur;
	}
	return cur[n] ;
}

