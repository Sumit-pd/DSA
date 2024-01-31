#include<bits/stdc++.h>
bool isPossible(vector<int> &arr , int minDist , int k )
{
    int cntCow = 1 ;
    int last = arr[0];
    for(int i = 1 ; i < arr.size() ; i++ ){
        if(arr[i] - last >= minDist ){
            //maintaining the distance 
            cntCow++;
            last = arr[i] ;
        }
        if(cntCow == k){
            return true ;
        }
    }
    return false ;
}
int aggressiveCows(vector<int> &arr, int k)
{
    int n = arr.size() ;
    //sort the array
    sort(arr.begin(),arr.end());
    //the first cow will be at 0th index
    int low = 1 ;
    int high = arr[n-1] - arr[0] ;
    while(low <= high){
        int mid = (low+high)/2;
        if(isPossible(arr,mid,k)==true){
            //increase the value since we need the maximum
            low = mid + 1;
        }
        else{
            //distance bhaut jayada ho gya
            high = mid - 1 ;
        }
    }
    return high;
}