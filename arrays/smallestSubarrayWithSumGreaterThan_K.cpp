//brute 
//time complexity : O(n2)
#include <bits/stdc++.h> 
int shortestSubarrayWithSumK(vector<int> &arr, int k)
{
    int ans = INT_MAX ;
    int n = arr.size() ;
    for(int i = 0 ; i < n ; i++ ){
        int sum = 0 ;
        for(int j = i ; j < n ; j++ ){
            sum += arr[j] ;
            if(sum >= k ){
                ans = min(ans,j-i+1);
            }
        }
    }
    if( ans == INT_MAX ){
        return -1 ;
    }
    return ans ;
}


//better