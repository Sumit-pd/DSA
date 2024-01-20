#include <bits/stdc++.h> 
//brute
#include <bits/stdc++.h> 
int helper(int ind , vector<int> &nums){
    if(ind == 0){
        return nums[ind];
    }
    if(ind < 0 ){
        return 0 ;
    }
    int ans1 = helper(ind-1,nums) ;
    int ans2 = nums[ind] + helper(ind-2,nums);
    return max(ans1,ans2);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size() ;
    return helper(n-1,nums);
}

//memoization


#include <bits/stdc++.h> 
int helper(int ind , vector<int> &nums,vector<int> &dp){
    if(ind == 0){
        return nums[ind];
    }
    if(ind < 0 ){
        return 0 ;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    int ans1 = helper(ind-1,nums,dp) ;
    int ans2 = nums[ind] + helper(ind-2,nums,dp);
    return dp[ind] = max(ans1,ans2);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size() ;
    vector<int> dp(n,-1);
    return helper(n-1,nums,dp);
}

//tabulation
//time complexity: O(n)
//space complexity : O(n)
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size() ;
    vector<int> dp(n+1,-1);
    dp[1] = nums[0] ;
    dp[0] = 0 ;
    for(int i = 2 ; i <= n ; i++ ){
        int ans1 = dp[i-1] ;
        int ans2 = nums[i-1] + dp[i-2];
        dp[i] = max(ans1,ans2);
    }
    return dp[n];
}

//space optimization

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size() ;
    int morePrev = 0 ;
    int prev = nums[0] ;
    for(int i = 1 ; i < n ;i++ ){
        int notPick = prev ;
        int pick = nums[i] + morePrev ;
        int cur = max(pick,notPick) ;
        morePrev = prev ;
        prev = cur ;
    }
    return prev;
}









