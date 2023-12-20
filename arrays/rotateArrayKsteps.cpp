//better
vector<int> rotateArray(vector<int> &arr , int k ){
    vector<int> temp ; 
    int n = arr.size() ;
    for(int i = 0 ; i < k ; i++ ){
        temp.push_back(arr[i]) ; // add the first k elements to the temp arr
    }
    for(int i = k ; i < n ; i++){
        arr[i-k] = arr[i]; // move the elements to the left by k steps
    }
    for (int i = n - k ; i < n; i++)
    {
        arr[i] = temp[ i - (n-k)] ; // move the elements back to the back of the array
    }
    return arr;
    //time complexity = O(n + k)
    // space complexity = o(k)
}
//optimal
void reverse(vector<int> &arr , int start , int end){
    while(start < end){
        swap(arr[start],arr[end]) ;
        start++ ;
        end-- ;
    }
}
vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size() ;
    reverse(arr,0,k-1) ;
    reverse(arr,k,n-1) ;
    reverse(arr,0,n-1) ;

    return arr ;

    // time compexity : O(2n)
    // space complexity : O(1)
}
