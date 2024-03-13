#include <bits/stdc++.h> 
int findSum(vector<int> arr , int n ) {
    int sum = 0 ; 
    for(int i = 0 ; i < n ;i++ ){
        sum += arr[i] ;
    }
    return sum ;
}
int maxSumAfterKflips(vector<int> &arr, int k, int n){
    sort(arr.begin() , arr.end() ) ;


    for(int i = 0 ; i < n ; i++ ){
        if(arr[i] >= 0 || k == 0  ){
            break ;
        }
        arr[i] *= -1 ;
        k--;
    }

    sort(arr.begin(),arr.end()) ;

    if(k > 0 ){
        if(k % 2 != 0 ){
            arr[0] *= -1 ;
        }
    }

    return findSum(arr,n) ;
}


#include <bits/stdc++.h> 
int maxSumAfterKflips(vector<int> &arr, int k, int n){
    sort(arr.begin(),arr.end()) ;
    for(int i = 0 ; i < k ; i++ ){
        if(arr[i] < 0){
            arr[i] = -arr[i] ;
        } 
        else if(arr[i] == 0) break ;
        else{
            if((k-i) % 2 == 0 ){
                break;
                //no need to move as this will not decrease the sum so we can add as much of negations
            }
            else{
                //negation of smallest positive integer
                arr[i] = -arr[i] ;
                break ;
            }
        }
    }

    int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
}
