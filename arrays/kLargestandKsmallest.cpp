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
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	vector<int> ans ;
	priority_queue<int> maxHeap ;
	priority_queue<int,vector<int>,greater<int>> minHeap ;
	for(int i = 0 ; i < n ; i++ ){
		maxHeap.push(arr[i]) ;
		minHeap.push(arr[i]) ;
	}
	int K = k ;
	while(k > 0 ){
	//this is for k smallest
		int front = minHeap.top() ;
		minHeap.pop() ;
		k--;
		if(k == 0 ){
			ans.push_back(front);
		}
	}
	while(K > 0 ){
	// this is for the k largest
		int front = maxHeap.top() ;
		maxHeap.pop() ;
		K--;
		if(K == 0 ){
			ans.push_back(front);
		}
	}
	return ans ;
	
		
}
