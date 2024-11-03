//memoization
#include<bits/stdc++.h>
int helper(int day , int last , vector<vector<int>> &points, vector<vector<int>> &dp ){
    if(day == 0){
        int maxi = 0 ;
        for(int i = 0 ; i < 3 ; i++ ){
            if(i!=last){
                maxi = max(maxi,points[0][i]) ;
            }
        }
        return maxi ;
    }
    if(dp[day][last] != -1){
        return dp[day][last] ;
    }
    int maxi = 0 ;
    for(int i = 0 ; i < 3 ; i++ ){
        if(i != last){
            int point = points[day][i] + helper(day-1,i,points,dp) ;
            maxi = max(maxi,point) ;
        }
    }
    return dp[day][last] = maxi ;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)) ;
    return helper(n-1,3,points,dp) ;
}

/********************/
//Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,0)) ;
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});
    for(int day = 1 ; day < n ; day++ ){
        for(int last = 0 ; last < 4 ; last++ ){
            int maxi = 0 ;
            for(int i = 0 ; i < 3 ; i++ ){
                if(i != last) {
                    int point = points[day][i] + dp[day - 1][i];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi ;
        }
    }
    return dp[n-1][3] ;
}