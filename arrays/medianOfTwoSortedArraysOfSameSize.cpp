// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ;
int findMedian(int arr1[] , int arr2[] , int n ){
    int md1 = -1 ;
    int md2 = -1 ;
    int i = 0 ;
    int j = 0 ;
    for(int cnt = 0 ; cnt <= n ; cnt++ ){
        if( i == n ){
            md1 = md2 ; // keeping track of previous value as we will be needing n-1 
            md2 = arr2[j] ;
            break ;
        }
        else if(j == n ){
            md1 = md2 ;
            md2 = arr1[i] ;
            break;
        }
        
        else if (arr1[i] <= arr2[j] ){
            md1 = md2 ;
            md2 = arr1[i] ;
            i++ ;
        }
        else{
            md1 = md2 ;
            md2 = arr2[j] ;
            j++ ;
        }
    }
    
    return (md2+md1)/2 ;
}
int main() {
    
    int arr1[5] = {1,2,3,4} ;
    int arr2[5] = {5,6,7,8} ;
    std::cout << findMedian(arr1,arr2,4) << std::endl;
    

    return 0;
}


/*
    since there are two arrays of same size so their multiple will be even and the median of even element is 
    ((n/2) + (n/2)+1)/2 
    so the middle element will be n-1 and n/2 in terms of 0 based indexing
*/

    