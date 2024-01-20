#include<bits/stdc++.h>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> mp ;
	int cnt = 0 ; 
	for(int i = 0 ; i < n ; i++ ){
		int target = k + arr[i] ;
		cnt += mp[target] ;
		//checking for the negative absolutes
		if(k != 0 ){
			//excluding the 0 
			target = arr[i] - k ;
			cnt += mp[target];
		} 
		mp[arr[i]]++;
	}
	return cnt ;
}