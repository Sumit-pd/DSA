//brute
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int zeros = 0 ;
    int ones = 0 ;
    int twos = 0 ;
    for(auto it : arr){
        if(it == 0){
            zeros++ ;
        }
        if(it == 1){
            ones++ ;
        }
        if(it == 2){
            twos++ ;
        }
    }

    for(int i = 0 ; i< zeros;i++){
        arr[i] = 0 ;
    }
    for(int i = zeros ; i < zeros + ones ; i++ ){
        arr[i] = 1 ;
    }
    for(int i = zeros + ones ; i < n ; i++ ){
        arr[i] = 2 ;
    }
    //TC:O(2N)
}
void sortArray(vector<int>& arr, int n)
{
    int low = 0 ;
    int mid = 0 ;
    int high = n - 1 ;
    while(mid <= high ){
        if(arr[mid] == 0 ){
            swap(arr[low],arr[mid]) ; // 0 will be brought to the front
            low++ ;
            mid++;
        }
        else if(arr[mid] == 1 ){
            mid++ ;
        }
        else{
            swap(arr[mid] , arr[high]) ;
            high-- ;
            //high will be sent to the last of the array
        }
    }
    //TC : O(N)
}

