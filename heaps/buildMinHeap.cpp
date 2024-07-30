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


// iterative


#include <bits/stdc++.h> 
void heapify(vector<int> &arr , int n , int i  ){
	while(true){
		int largest = i ;
		int left = 2 * i + 1 ; 
		int right = 2 * i + 2 ;
		
		if(left < n && arr[left] > arr[largest]){
			largest = left ;
		}
		if(right < n && arr[right] > arr[largest]) {
			largest = right ;
		}
		if(i != largest){
			swap(arr[largest],arr[i]);
			i = largest;
		}
		else break ;
	}
}
vector<int> buildHeap(vector<int> arr, int n)
{	
	for(int i = n /2 - 1 ; i>= 0 ; i-- ){
		heapify(arr,n,i) ;
	}
	return arr;
}