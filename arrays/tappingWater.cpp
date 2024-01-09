//brute force
long long maxHeight(long long * arr , int start , int end) {
    long long maxi = 0 ;
    for(int i = start ; i <= end ; i++){
        maxi = max(maxi,arr[i]) ;
    }
    return maxi;
}
long long getTrappedWater(long long* arr, int n) {
    long long ans = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        long long leftMax = maxHeight(arr,0,i);
        long long rightMax = maxHeight(arr,i,n-1);
        ans += min(leftMax,rightMax) - arr[i];
    }
    return ans ;
    //time complexity : O(n2)
    //space complexity:O(1)

}


//better
long long getTrappedWater(long long* arr, int n) {
    long long *preMax = new long long[n] ; 
    preMax[0]=arr[0] ;
    long long *sufMax = new long long[n] ;
    sufMax[n-1] = arr[n-1] ;
    //fixing the preMax array
    for(int i = 1 ; i < n ; i++){
        preMax[i] = max(arr[i],preMax[i-1]);
    }
    //fixing the suffMax array
    for(int i = n-2 ; i >=0 ; i-- ){
        sufMax[i] = max(arr[i],sufMax[i+1]);
    }


    long long ans = 0;
    for(int i = 0 ; i < n ; i++ ){
        ans += min(preMax[i],sufMax[i]) - arr[i];
    }
    return ans ;
//time complexity:O(3N)
//space complexity : O(2N)``

}
