#include <bits/stdc++.h> 
void heapify(vector<int> &arr , int n , int i ){
    int smallest = i ;
    int left = 2 * i + 1 ;
    int right = 2 * i + 2 ;
    if(left < n && arr[left] < arr[smallest] ){
        smallest = left ;
    }
    if(right < n && arr[right] < arr[smallest] ){
        smallest = right ;
    }

    if(i != smallest){
        swap(arr[i] , arr[smallest]) ;
        heapify(arr,n,smallest) ;
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size() ;
    for(int i = n -1 ; i >= 0 ; i-- ){
        heapify(arr,n,i) ;
    }
    return arr ;
}
