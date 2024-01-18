//brute
// Time Complexity : O(n)
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans = {-1,-1 };
    for(int i = 0 ; i < n ; i++ ){
        if(arr[i] == k ){
            ans.first = i ;
            break ;
        }
    }
    for(int i = n -1 ; i >= 0 ; i-- ){
        if(arr[i] == k ){
            ans.second = i ;
            break ;
        }
    }
    return ans ;
}

//using lower bound and upper bound
#include<bits/stdc++.h>
pair<int, int> firstAndLastPosition(vector<int>& arr,
 int n, int k)
{
    pair<int,int> ans ;
    int i = lower_bound(arr.begin(),arr.end(),k) - arr.begin();
    if(i>= 0 && i < n && arr[i] == k){
        ans.first = i ;
    }
    else{
        ans.first = -1 ;
    }

    int j = upper_bound(arr.begin() , arr.end() , k ) - arr.begin() ;
    if(j > 0 && j <= n && arr[j-1] == k ){
        ans.second = j-1 ;
    }
    else {
        ans.second = -1 ;
    }
    return ans ;
}

//optimal2
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> ans ; 
    int high = n-1 ;
    int low = 0 ;
    while(low <= high){
        int mid = (low+high)/2 ;
        if(arr[mid] >= k ){
            high = mid - 1 ;
        }
        else{
            low = mid+1;
        }
    }
    if(low < 0 || low >= n || arr[low] != k ){
        ans.first = -1 ;
    }
    else {
        ans.first = low ;
    }

    high = n-1 ;
    low = 0 ;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > k){
            high = mid -1 ;
        }
        else {
            low = mid +1 ;
        }
    }

    if(high < 0 || high >= n || arr[high] != k ){
        ans.second = -1 ;
    }
    else{
        ans.second = high;
    }
    return ans ;
}
