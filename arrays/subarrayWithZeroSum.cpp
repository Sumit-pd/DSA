#include <bits/stdc++.h> 
int countSubarrays(int n, vector<int> &arr){
    // using the concept of presum
    unordered_map<int,int> mp ;
    mp[0] = 1 ;
    int presum = 0 ;
    int count = 0 ;
    //indicates there is 0 with frequency of 1 as the presum initially is 0
    for(int i = 0 ; i < n ; i++ ){
        presum += arr[i] ;
        count += mp[presum] ;
        mp[presum]++ ;
    }
    return count ;
} 


int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // using the concept of presum
    unordered_map<int,int> mp ;
    int n = arr.size() ;
    mp[0] = 1 ;
    int presum = 0 ;
    int count = 0 ;
    //indicates there is 0 with frequency of 1 as the presum initially is 0
    for(int i = 0 ; i < n ; i++ ){
        presum += arr[i] ;
        count += mp[presum - k ] ;
        mp[presum]++ ;
    }
    return count ;
}
