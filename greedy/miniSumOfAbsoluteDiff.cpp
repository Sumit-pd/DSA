#include <bits/stdc++.h> 

//to find the minimize we need to substrace the minimum with the minimum element and the maximum with the maximum element
// this way we will result in finding the minimum difference 
int minimumDifference(vector<int> &arr1, vector<int> &arr2, int n)
{
	sort(arr1.begin() , arr1.end() ) ;

	sort(arr2.begin() , arr2.end() ) ;


	int sum = 0 ;

	for(int i = 0 ; i < n ; i++ ){
		sum += abs(arr1[i] - arr2[i]) ;
	}

	return sum ;
}
