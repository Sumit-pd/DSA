/****************************MEMOIZATION***********************************/
#include<bits/stdc++.h>
int helper(int  i , int j , string s1 , string s2 , vector<vector<int>> &dp ){
    if( j < 0 ) return 1 ;
    if( i < 0 ) return 0 ;

    if(dp[i][j] != -1 ){
        return dp[i][j] ;
    }

    if(s1[i] == s2[j] ){
        return dp[i][j] = helper(i-1,j-1,s1,s2,dp) + helper(i-1,j,s1,s2,dp) ;
    }
    return dp[i][j] = helper(i-1,j,s1,s2,dp) ;
}
int distinctSubsequences(string &str, string &sub)
{
	int n = str.length() ;
    int m = sub.length() ;
    vector<vector<int>> dp(n,vector<int>(m,-1)) ;
    return helper(n-1,m-1,str,sub,dp) ;
}
/****************************TABULATION******************************/


int distinctSubsequences(string &str, string &sub)
{
	int n = str.length() ;
    int m = sub.length() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    // 1st base case

    for(int i = 0 ; i <= n ; i++ ){
        dp[i][0] = 1 ;
    }


    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++ ){
             if(str[i-1] == sub[j-1] ){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  ;
            }
            else dp[i][j] = dp[i-1][j]  ;
        }
    }
    return dp[n][m] ;
}



/********************************************SPACE OPTIMIZATION*************************************************/
#include<bits/stdc++.h>
int prime = 1e9+7;
int distinctSubsequences(string &str, string &sub)
{
	int n = str.length() ;
    int m = sub.length() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    vector<int> prev(m+1,0) ;

    prev[0] = 1 ;
    for(int i = 1 ; i <= n ; i++ ){
        vector<int> cur(m+1,0) ;
        cur[0] =1 ;
        for(int j = 1 ; j <= m ; j++ ){
             if(str[i-1] == sub[j-1] ){
                cur[j] =( prev[j-1] + prev[j] ) % prime  ;
            }
            else cur[j] = prev[j]  ;
        }
        prev = cur ;
    }
    return prev[m] ;
}

/***********************************1D SPACE OPTIMIZATION*******************************/

#include<bits/stdc++.h>
int prime = 1e9+7;
int distinctSubsequences(string &str, string &sub)
{
	int n = str.length() ;
    int m = sub.length() ;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    vector<int> prev(m+1,0) ;

    prev[0] = 1 ;
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = m ; j >= 1 ; j-- ){
             if(str[i-1] == sub[j-1] ){
                prev[j] =( prev[j-1] + prev[j] ) % prime  ;
            }
        }
    }
    return prev[m] ;
}

