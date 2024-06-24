#include <bits/stdc++.h> 
//ye kara na to interviewer bhaga dega
int squareRoot(int a)
{
	return sqrt(a);
}

// using the linear search way 
//Time complexity : O(a)

int squareRoot(int a)
{
	if(a==0){
		return 0 ;
	}
	int ans = 1 ;
	// we need to just find the smallest decimal value and for that we need to find the minimum square of a number
	for(int i = 1 ; i <= a ; i++ ){
		if(i*i <= a){
			ans = i ;
		}
		else{
			break ;
		}
	}
	return ans;
}

//Binary Search
#include <bits/stdc++.h> 
int squareRoot(int a)
{
	if(a==0){
		return 0 ;
	}
	int low = 1 ;
	int high = a ;
	while(low <= high){
		long long mid = (low+high)/2 ; // when we multiply mid and mid the value may go out of range
		if(mid*mid <= a){
			low = mid+1;
		}
		else{
			high = mid - 1; 
		}
	}
	return high;
}
