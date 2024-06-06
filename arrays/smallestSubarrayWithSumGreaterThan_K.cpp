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
//time complexity O(2n)
// the sw can go on to i and then i can go on to n

#include <bits/stdc++.h> 
int minSubArrayLen(vector<int>& arr, int target, int n) {
    int mini = 1e9 ;
    int sum = 0 ;
    int i = 0 , sw = 0 ;
    while(i < n){
        sum += arr[i] ;
        if(sum > target){
            mini = min(mini,i-sw+1) ;
            while(sum > target && sw < i){
                sum -= arr[sw] ;
                sw++ ;  
                if(sum > target){
                    mini = min(mini,i-sw+1) ;
                }
            }
        }
        i++ ;
    }
    return mini != 1e9 ? mini : 0 ;
}
