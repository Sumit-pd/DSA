/*In brute we will use linear search*/


//optimal 
//time complexity: O(logn)
int equalIndex(vector<int> &arr, int n){	
	int low = 0 ;
	int high = n -1 ;
	while(low<=high){
		int mid = (low+high)/2 ;
		if(arr[mid] >= mid ){
			high = mid - 1 ;
		}
		else{
			low = mid + 1 ;
		}
	}
	if(low < 0 || low >= n ||arr[low] != low){
		return -1 ;
	}
	return low ;

}