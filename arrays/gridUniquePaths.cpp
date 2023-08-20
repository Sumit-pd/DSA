#include <bits/stdc++.h>
using namespace std;

// better
// time complexity : O(mxn)
// space complexity : O(mxn)
int helper(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int bottom = helper(i + 1, j, m, n, dp);
    int right = helper(i, j + 1, m, n, dp);
    return dp[i][j] = bottom + right;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(0, 0, m, n, dp);
}

// best
int uniquePaths(int m, int n)
{
    // find the (m+n-2) C (m -1)
    // here the m + n - 2 is the total number of steps  we will be taking
    int r = m - 1;
    int N = m + n - 2;
    double ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = ans * (N - r + i) / i;
    }
    return (int)ans ;
}