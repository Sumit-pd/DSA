/*
optimal solution
time complexity = O(N)
space xomplexity = O(1)
*/

#include <bits/stdc++.h>
int subarrayWithMaxProduct(vector<int> &arr){
	int n = arr.size() ;
	int maxi = INT_MIN ; // the maximum could be a negative number
	int pre = 1 ;
	int suff = 1 ;
	for(int i = 0 ; i < n ; i++ ){
		if(pre == 0 ) pre = 1 ;
		if(suff == 0 ) suff = 1 ;
		pre = pre * arr[i] ;
		suff = suff * arr[n - i - 1 ] ;
		maxi = max(maxi , max(pre,suff)) ;
	}
	return maxi ;
}