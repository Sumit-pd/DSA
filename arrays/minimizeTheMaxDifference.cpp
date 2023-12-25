#include<bits/stdc++.h>
int minimizeMaximum(int arr[], int n, int k)
{
    sort(arr,arr+n) ;
    int ans = (arr[n -1])  - (arr[0]) ;
    for(int i = 1 ; i < n ; i++ ){
        int maxi = max(arr[i-1] + k ,  arr[n-1] - k) ;
        int mini = min(arr[i] - k , arr[0] + k) ;
        ans = min(ans , maxi - mini) ;
    }
    return ans ;
    
}
