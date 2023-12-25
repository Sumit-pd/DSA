// brute
// we are generating all the subarray and finding the sum of each and finding the maximum
long long maxSubarraySum(vector<int> arr, int n)
{
    long long ans = -1e9 ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = i ; j < n ;j++){
            long long smallSum = 0 ;
            for(int k = i ; k <= j ; k++){
                smallSum += arr[k] ; // i - k is an subarray
            }
            ans = max(ans, smallSum);
        }
    }
    return ans ;
    //time complexity : O(n3)
}
//better
// int the above approach we are unnecessarily using the 3rd array 
// each iteration of j will generate a subarray
long long maxSubarraySum(vector<int> arr, int n)
{
    long long ans = -1e9 ;
    for(int i = 0 ; i < n ; i++ ){
        long long smallSum = 0 ;
        for(int j = i ; j < n ;j++){
            smallSum += arr[j] ;
            ans = max(ans, smallSum); // every interation is an subarray
        }
        
    }
    return ans ;
    /* time complexity : O(n2) */
}


//this algo avoids the use of negative sum
// the intution is when we find a negative sum of and subarray we will discard the sum and reset it to zero
long long maxSubarraySum(vector<int> arr, int n)
{
    long long ans = 0 ;
    long long sum = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        sum += arr[i] ;
        ans = max(ans,sum);
        if(sum < 0 ){
            sum = 0 ;
        }
    }
    return ans ;
}