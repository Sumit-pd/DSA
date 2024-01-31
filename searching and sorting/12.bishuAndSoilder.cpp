#include<bits/stdc++.h>
using namespace std ;
int main(){
	int n ;
	//arr of soldiers with various powers
	cin>> n ;
	int *arr = new int[n];
	for(int i = 0 ; i < n; i++ ){
		int x;
		cin>>x ;
		arr[i] = x ;
	}
	//the number of rounds
	int q ;
	cin>>q ;
	sort(arr,arr+n) ;

	// this is the prev sum
	int *prev = new int[n+1] ;
	prev[0] = 0 ;
	for(int i = 1 ; i <= n ; i++ ){
		prev[i] = prev[i-1] + arr[i-1];
	}
	//q rounds
	while(q--){
		//this will the vaired power of the bishu which will change in every round 
		int x ;
		cin>>x ;
		
		// number of soldier bishu can kill
		int ind = upper_bound(arr,arr+n,x) - arr ;
		cout<<ind<<" "<<prev[ind] <<endl;

	}
	
	return 0 ;
}