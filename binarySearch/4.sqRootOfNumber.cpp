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
		int mid = (low+high)/2 ;
		if(mid*mid <= a){
			low = mid+1;
		}
		else{
			high = mid - 1; 
		}
	}
	return high;
}
