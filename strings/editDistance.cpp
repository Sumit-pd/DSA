#include <bits/stdc++.h>
//memoization with sifting of index
int helper(string str1 , string str2 , int i , int j,vector<vector<int>> &dp ){
    if(i == 0){
        return j;
    }
    if(j == 0 ){
        return i ;
    }
    if(dp[i][j] != -1){
        return dp[i][j] ;
    }
    if(str1[i-1] == str2[j-1]){
        return dp[i][j] = helper(str1,str2,i-1,j-1,dp) ;
    }
    else {
        //replace
        int replace = helper(str1,str2,i-1,j-1,dp);
        //delete
        int deleteChar = helper(str1,str2,i-1,j,dp);
        //insert
        int insertChar = helper(str1,str2,i,j-1,dp);
        return dp[i][j] = 1 + min(replace,min(deleteChar,insertChar)) ;
    }
}
int editDistance(string str1, string str2)
{
    int n =  str1.length() ;
    int m = str2.length() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int ans = helper(str1 ,str2 ,n , m  ,dp);
    return ans ;
}

//tabulation
#include <bits/stdc++.h>
int editDistance(string str1, string str2)
{
    int n =  str1.length() ;
    int m = str2.length() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0 ; i <= n ; i++ ){
        dp[i][0] = i ;
    }
    for(int j = 0 ; j <= m ; j++ ){
        dp[0][j] = j ;
    }
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
            if(str1[i-1] == str2[j-1]){
              dp[i][j] = dp[i-1][j-1] ;
            }
            else {
                //replace
                int replace = dp[i-1][j-1] ;
                //delete
                int deleteChar = dp[i-1][j];
                //insert
                int insertChar =dp[i][j-1];
                dp[i][j] = 1 + min(replace,min(deleteChar,insertChar)) ;
            }
        }
    }
    return dp[n][m] ;
}


// going toward the space optimization
#include <bits/stdc++.h>
int editDistance(string str1, string str2)
{
    int n =  str1.length() ;
    int m = str2.length() ;
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    vector<int> prev(m+1,0);
    vector<int> cur(m+1,0);
    for(int i = 0 ; i <= m ; i++ ){
        prev[i] = i ;
        // cur[i] = i ;
    }
    for(int i = 1 ; i <= n ; i++ ){
        cur[0] = i ;
        for(int j = 1 ; j <= m ; j++ ){
            if(str1[i-1] == str2[j-1]){
              cur[j] = prev[j-1] ;
            }
            else {
                //replace
                int replace = prev[j-1] ;
                //delete
                int deleteChar = prev[j];
                //insert
                int insertChar =cur[j-1];
                cur[j] = 1 + min(replace,min(deleteChar,insertChar)) ;
            }
        }
        prev = cur ;
    }
    return prev[m] ;
}