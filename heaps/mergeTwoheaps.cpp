#include <bits/stdc++.h> 
void heapify(vector<int> &arr , int n , int i ){
    int largest = i ;
    int left = 2 * i + 1 ;
    int right = 2 * i + 2 ;
    if(left < n && arr[largest] < arr[left] ){
        largest = left ;
    }
    if(right < n && arr[largest] < arr[right] ){
        largest = right ;
    }
    if(largest != i ){
        swap(arr[largest],arr[i] ) ;
        heapify(arr,n,largest) ;
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    vector<int> ans ;
    for(int it : arr1){
        ans.push_back(it) ;
    }
    for(int it : arr2){
        ans.push_back(it) ;
    }
    
    for(int i = (n+m)/2 - 1   ; i >= 0 ; i-- ){
        heapify(ans,ans.size(),i) ;
    }

    return ans ;
}