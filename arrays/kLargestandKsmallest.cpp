#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<int> ans;
	ans.push_back(arr[k-1]);
	ans.push_back(arr[n-k]);
	return ans;
}
/*
    Time complexity: O(N + KlogN)
    Space complexity: O(N)

    Where ‘N’ is the size of the given array and K is given integer.
*/
#include <queue>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> result(2);

    // Build Min-Heap from the given array.
    priority_queue<int, vector<int>, greater<int>> minHeap(arr.begin(), arr.end());

    // Pop from Min-Heap exactly K-1 times
    for(int i = 1; i < k; i++) 
    {
        minHeap.pop();
    }

    // Kth smallest element.
    result[0] = minHeap.top();

    // Build Max-Heap from the given array.
    priority_queue<int> maxHeap(arr.begin(), arr.end());

    // Pop from Max-Heap exactly K-1 times
    for(int i = 1; i < k; i++) 
    {
        maxHeap.pop();
    }

    //Kth largest element.
    result[1] = maxHeap.top();

    return result;
}


//using quick select

#include <bits/stdc++.h> 
int partition(vector<int> &arr , int low , int high){
	int randNum = rand()%(high-low + 1) + low;
	swap(arr[low],arr[randNum]) ;
	int pivot = arr[low] ;
	int i = low +1;
	int j = high ;
	while(i <= j){
		while(arr[i] < pivot && i <= j){
			i++ ;
		}
		while(arr[j] >= pivot && i <= j){
			j-- ;
		}
		if(i < j ){
			swap(arr[i],arr[j]) ;
		}
	}
	swap(arr[j],arr[low]) ;
	return j;
}
int helper(vector<int> &arr ,int size, int K , int low , int high){
	if(low > high) return -1 ;

	int part = partition(arr,low,high) ;
	if(part == arr.size() - K){
		return arr[part] ;
	}
	else if(part < arr.size() - K){
		return helper(arr,size,K,part+1,high) ;
	}
	else{
		return helper(arr,size,K,low,part-1) ;
	}
}
int kthLargest(vector<int>& arr, int size, int K)
{
	return helper(arr,size,K,0,size-1) ;
}
