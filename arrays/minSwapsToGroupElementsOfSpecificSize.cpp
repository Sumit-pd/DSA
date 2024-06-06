#include <bits/stdc++.h> 

/*
	-whenever you see to group element of a specific size then we can apply sliding window
	- jitne non fav honge ek group me autne swaps
*/
int minimumSwaps(vector<int> &arr, int n, int k)
{
	int windowSize = 0 ;
	for(int it : arr ){
		if(it <= k ){
			windowSize++ ;
		}
	}
	int ans = 1e9 ;
	int nonFav = 0;
	for(int i = 0 ; i < windowSize ; i++ ){
		if(arr[i] > k ){
			nonFav++ ;
		}
	}
	int i = 0 ;
	int j = windowSize-1 ;
	while(j < n ){
		ans = min(ans,nonFav);
		j++ ;
		if(j<n && arr[j] > k ) nonFav++ ;
		if(i<n && arr[i] > k ) nonFav-- ;
		i++ ;
	}

	if( ans == 1e9 ) return 0 ;
	return ans ;
	

}
