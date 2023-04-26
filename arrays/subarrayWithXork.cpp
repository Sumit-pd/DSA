/*brute will be using three for loops 
-time complexity : O(N3)
-space complexity : O(1)
*/
/*
better will be use of two for loops 
-time complexity : O(n2)
-space complexity : O(1)
*/
/*
time complexity : O(N) or O(N LogN ) 
space complexity : O(N) 
*/
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size() ;
    int xr = 0;
    map<int,int> mp ; // this will be storing the number of xors previously stored and its count
    mp[xr]++ ; // initializing the 0 xor with 1 as a checklist if the entire array is xored
    int cnt = 0 ;
    
    for(int i = 0 ; i < n ; i++ ){
        xr = xr ^ a[i];
        int x = xr ^ b ;
        cnt += mp[x] ;
        mp[xr]++ ;
    }
    return cnt ;
    
}