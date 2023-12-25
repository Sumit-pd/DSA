#include <bits/stdc++.h> 
void reverseArr(vector<int> &arr , int start , int end ){
    while(start < end ){
        swap(arr[start],arr[end]) ;
        start++ ;
        end-- ;
    }
}
vector<int> nextPermutation(vector<int> &arr, int n)
{
    //find the break point 
    int ind  = -1 ;
    for(int i = n - 2 ; i >= 0 ; i-- ){
        if(arr[i] < arr[i+1]) {
            ind = i ;
            break ;
        }
    }
    if(ind == -1){
        // this is the last permutation so return the first permutation
        reverseArr(arr,0,n-1) ;
        return arr ;
    }
    //find the next greater element from right of the array
    for(int i = n -1 ; i>= ind ; i++ ){
        if(arr[i] > arr[ind]){
            swap(arr[ind] , arr[i]) ;
            break ;
        }
    }
    reverseArr(arr,ind + 1 , n -1 ) ;
    return arr ;


}