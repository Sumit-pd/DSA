#include <bits/stdc++.h> 
int palindrome(vector<int> arr)
{
	int n = arr.size() ;
	if(n == 1 ){
		return 0 ;
	}

	vector<long long> A(n);
	for(int i = 0 ; i < n ;i++ ){
		A[i] = (long long)arr[i] ;
	}
	int i = 0 ;
	int j = n-1 ;
	int cnt = 0 ;
	while(i<= j){
		if(A[i] == A[j] ){
			i++ ;
			j-- ;
		}
		else if(A[i] < A[j]) {
			i++;
			A[i] = A[i] + A[i-1] ;
			cnt++ ;
		}
		else{
			j-- ;
			A[j] = A[j+1] + A[j] ;
			cnt++ ;
		}
	}
	return cnt ;
}

