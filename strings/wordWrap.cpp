class Solution {
    int helper(vector<int> &nums ,int dp[][2000] , int i , int rem,int k ){
        // i will be the index we will be operating and  rem denotes the amount of characters left in a line
        if(i >= nums.size() ){
            return 0 ;
        }
        if( dp[i][rem] != -1 ){
            return dp[i][rem];
        }
        int ans ;
        if(nums[i] > rem ){
            ans = (rem+1) * (rem+1) + helper(nums,dp,i+1,k-nums[i]-1,k);
        }
        else{
            int count1 = (rem+1) * (rem+1) + helper(nums,dp,i+1,k-nums[i]-1,k);
            int count2 = helper(nums,dp,i+1,rem-nums[i]-1,k);
            ans = min(count1,count2);
        }
        dp[i][rem] = ans;
        return ans ;
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size() ;
        // vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        int dp[1000][2000];
        memset(dp,-1,sizeof(dp));
        return helper(nums,dp,0,k,k);
        
    } 
};