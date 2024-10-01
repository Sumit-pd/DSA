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
        // we can start with first non leaf node 
        // in almost complete binary tree half elements are leaf nodes
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
         // since the smallest element is at the starting it will be  placed in the end of array
         //as it is a min heap so it will be storing the elements in descending order.
        heapify(arr,size-1,0);
        size--;
    }
    
}

void maxHeapify(vector<int> &arr , int n , int i){
    int largest = i ;
    int left = 2*i ;
    int right = 2*i+1 ;
    if(left <= n && arr[largest] < arr[left]){
        largest = left ;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right ;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest) ;
    }
}
void heapSortAcsc(vector<int> &arr , int n ){
    int ind = n;
    while(ind >= 1){
        int last = ind ;
        swap(arr[last],arr[1]) ;
        maxHeapify(arr,n,ind) ;
        ind-- ;
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





/*****************************************************************************************************************************************************/





// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std ;
void maxHeapify(vector<int> &arr , int n , int i){
    int largest = i ;
    int left = 2*i+1 ;
    int right = 2*i+2 ;
    if(left < n && arr[largest] < arr[left]){
        largest = left ;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right ;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n,largest) ;
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size() ;
    for(int i = n/2 - 1; i >= 0 ; i-- ){
        // we can start with first non leaf node 
        // in almost complete binary tree half elements are leaf nodes
        maxHeapify(arr,n,i) ;
    }
    return arr ;
}
void heapSortAcsc(vector<int> &arr , int n ){
    int ind = n;
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);  // Corrected swapping based on zero-indexed array
        maxHeapify(arr, i, 0);  // Reduced heap size by passing 'i' instead of 'n'
    }
}

int main() {
    vector<int> arr = {12,23,32,321,1};
    vector<int> heap = buildMinHeap(arr) ;
    heapSortAcsc(heap,5) ;
    for(int i : heap ){
        cout<< i <<" ";
    }

    return 0;
}
