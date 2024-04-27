// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std ;
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
    for(int i = n/2 - 1; i >= 0 ; i-- ){
        heapify(arr,n,i) ;
    }
    return arr ;
}

void heapSort(vector<int> &arr){
    int size = arr.size()-1 ;
    while (size >= 0 )
    {
        int last = size ;
        swap(arr[0],arr[last]);
        heapify(arr,size-1,0);
        size--;
    }
    
}

int main() {
    vector<int> arr = {12,23,32,321,1};
    vector<int> heap = buildMinHeap(arr) ;
    heapSort(heap) ;
    for(int i : heap ){
        cout<< i <<" ";
    }

    return 0;
}