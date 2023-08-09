vector<int> nextGreaterPermutation(vector<int> &arr) {
    int n = arr.size() ;
    int ind = -1 ; // for finding the breakpoint
    for(int i = n - 2 ; i >= 0 ; i-- ){
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }//O(n)
    if(ind == -1 ){
        reverse(arr.begin() , arr.end() ) ;
        return arr ;
    }
    //O(n)
    //finding the element that is greater than the arr[ind]
    for(int i = n - 1 ;i > ind ;i-- ){
        if(arr[i] > arr[ind]){
            swap(arr[i] , arr[ind]) ;
            break; 
        }
    }
    reverse(arr.begin() + ind + 1 , arr.end()) ; // +1 is added because the array is based on zero based indexing
    return arr ;
}

// for better use next_permuation from c++ stl