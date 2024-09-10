#include <bits/stdc++.h> 
// we need to know the range of the smallest and largest element, this will only be used when the range is small
// in a limited range of elements
// this is a stable sorting algo
vector<int> sort(int n, vector<int> &arr)
{
    int maxi = *max_element(arr.begin(),arr.end()) ;
    int mini = *min_element(arr.begin(),arr.end()) ;
    vector<int> count(maxi - mini + 1 ) ;
    for(auto it : arr){
        count[it-mini]++ ;
    }

    for(int i = 1 ; i < count.size() ; i++ ){
        count[i] += count[i-1] ;
    }

    vector<int> ans(n) ;
    for(int i = n -1 ; i>= 0 ; i--){
        int ind = count[arr[i]- mini] - 1 ;
        ans[ind] = arr[i] ;
        count[arr[i]- mini]--;
    }

    return ans ;
}


// for decending order
vector<int> sort(vector<int> &arr , int n){
    int mini = *min_element(arr.begin(),arr.end()) ;
    int maxi = *max_element(arr.begin(),arr.end()) ;

    vector<int> cnt(maxi-mini+1,0) ;
    for(int it : arr){
        cnt[it-mini]++ ;
    }
    for(int i = 1 ; i < cnt.size() ; i++ ){
        cnt[i] += cnt[i-1] ;
    }

    vector<int> ans(n) ;
    for(int i = 0 ; i < n;i++ ){
        int ind = cnt[arr[i] - mini ] -1 ;
        cnt[arr[i]-mini]-- ;
        ans[n-1-ind] = arr[i]; 
    }
    return ans ;
}


//time complexity : O(n+k)
//space complexity : O(k)