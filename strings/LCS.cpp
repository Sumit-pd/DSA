//brute 
// time complexity : o(2^n) + O(2^m)
int helper(string s , string t , int i ,int j ){
    if(i < 0 || j < 0 ){
        return 0 ;
    }
    if(s[i] == t[j]){
        return 1 + helper(s,t,i-1,j-1);
    }
    return max(helper(s,t,i-1,j),helper(s,t,i,j-1));
}
int lcs(string s, string t)
{
    int n = s.size() ;
    int m = t.size() ;
    // vector
	return helper(s,t,n-1,m-1);
}

//better 
//time complexity : O(n*m)
//space complexity : O(n*m) + O(n*m)
//one is for the dp array and the other is for auxilary stack space
int helper(string s , string t , int i ,int j,vector<vector<int>> &dp ){
    if(i < 0 || j < 0 ){
        return 0 ;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i] == t[j]){
        return dp[i][j] = 1 + helper(s,t,i-1,j-1,dp);
    }
    return dp[i][j] = max(helper(s,t,i-1,j,dp),helper(s,t,i,j-1,dp));
}
int lcs(string s, string t)
{
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n,vector<int>(m,-1));
	return helper(s,t,n-1,m-1,dp);
}

// after shifting the index
// n => n+1 m=> m+1 
// i => i -1 , j => j-1
#include<bits/stdc++.h>
int helper(string s , string t , int i ,int j,vector<vector<int>> &dp ){
    if(i == 0 || j == 0 ){
        return 0 ;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(s[i-1] == t[j-1]){
        return dp[i][j] = 1 + helper(s,t,i-1,j-1,dp);
    }
    return dp[i][j] = max(helper(s,t,i-1,j,dp),helper(s,t,i,j-1,dp));
}
int lcs(string s, string t)
{
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
	return helper(s,t,n,m,dp);
}



//tabulation
// the space compelexity for the stack will be removed
int lcs(string s, string t)
{
    int n = s.size() ;
    int m = t.size() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0 ; i <= n ; i++ ){
        dp[i][0] = 0 ;
    }
    for(int i = 0 ; i <= m ; i++ ){
        dp[0][i] = 0 ;
    }

    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
	return dp[n][m];
}

//space optimized 
//time compliexity : O(N*M)
//space complexity : O(M)
// where we are using the previous row we used previous array 
int lcs(string s, string t)
{
    int n = s.size() ;
    int m = t.size() ;
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);

    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            if(s[i-1] == t[j-1]){
                cur[j] = 1 + prev[j-1];
            }
            else{
                cur[j] = max(prev[j],cur[j-1]);
            }
        }
        prev = cur;
    }
	return cur[m];
}