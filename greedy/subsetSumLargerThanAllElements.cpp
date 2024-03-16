#include <bits/stdc++.h> 
int findSum(vector<int> arr , int n ){
	int sum = 0 ;
	for(int i = 0 ; i < n ; i++ ){
		sum += arr[i] ;
	}
	return sum ;
}
int smallestSubset(vector < int > arr, int n) 
{
	sort(arr.begin() , arr.end() , greater<int>() )  ;

	int sum = findSum(arr,n) ;

	int smallSum = 0 ;

	int cnt = 0 ;
	for(int i = 0 ; i < n ; i++) {
		if(arr[i] <= 0 ){
			continue ;
		}
		smallSum += arr[i] ;
		cnt++ ;
		if(smallSum > sum - smallSum){
			return cnt ;
		}
	}
}