//brute
int findPeakElement(vector<int> &arr) {
    int n = arr.size() ;
    if(n== 1){
        return 0 ;
    }
    if(arr[0] >= arr[1]){
        return 0 ;
    }
    if(arr[n-1] >= arr[n-2]){
        return n-1;
    }
    for(int i = 1 ; i < n -1 ; i++ ){
        if(arr[i] > arr[i+1] && arr[i-1] < arr[i]){
            return i ;
        }
    }
}
int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    int low = 0 ;
    int high = n -1 ;
     if (arr[0] >= arr[1])
        return 0;
    if (arr[n - 1] >= arr[n - 2])
        return n - 1;
    while(low <= high){
        int mid = (low + high)/2 ;
        if(arr[mid] >= arr[mid +1] && arr[mid] >= arr[mid - 1] ){
            return mid ;
        }
        else if(arr[mid] < arr[mid +1] ){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}
