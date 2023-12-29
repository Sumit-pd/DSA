int lowerBound(vector<int> arr, int n, int x) {
	int ans = n ;
	//assuming the lowet bound to be the index after the last element
	//we need to find the element greater than equal to x
	int low = 0 ;
	int high = n-1 ;
	while(low <= high){
		int mid = (low + high)/2 ;
		if(arr[mid] >= x ){
			ans = mid ;
			high = mid -1 ;
		}
		else{
			low = mid + 1 ;
		}
	}
	return ans ;
}


int upperBound(vector<int> &arr, int x, int n){
	int ans = n ;
	//assuming the upper bound to be the index after the last element
	//we need to find the element greater than th x
	int low = 0 ;
	int high = n-1 ;
	while(low <= high){
		int mid = (low + high)/2 ;
		if(arr[mid] > x ){
			ans = mid ;
			high = mid -1 ;
		}
		else{
			low = mid + 1 ;
		}
	}
	return ans ;
}
