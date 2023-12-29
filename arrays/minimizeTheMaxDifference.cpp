#include<bits/stdc++.h>
int minimizeMaximum(int arr[], int n, int k)
{
    sort(arr,arr+n) ;
    int ans = (arr[n -1])  - (arr[0]) ;
    for(int i = 1 ; i < n ; i++ ){
        int maxi = max(arr[i-1] + k ,  arr[n-1] - k) ;
        int mini = min(arr[i] - k , arr[0] + k) ;
        // we are only comparing the mini and maxi with the last element because we can only add and subract once
        ans = min(ans , maxi - mini) ;
    }
    return ans ;
    
}
