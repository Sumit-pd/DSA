#include <bits/stdc++.h> 
//brute 
//time complexity : O(n2)
//space complexity : O(1) 
vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans(n,-1) ;
    for(int i = 0 ; i < n ;i++ ){
        int elem = arr[i] ;
        for(int j = i + 1 ; j < n ; j++ ){
            if(arr[j] > elem) {
                ans[i] = arr[j] ;
                break ;
            }
        }
    }
    return ans ;

}


/*
optimal

time complexity : O(N) 
space compleixty : O(N)
*/


#include<stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	vector<int> ans(n,-1) ;
	stack<int> st ;
	for(int i = n -1 ; i >= 0 ; i-- ){

        //removing all the elements that are smaller than or equal to the top of the stack
		while( !st.empty() && st.top() <= arr[i] ){
			st.pop() ;
		}

		if(st.empty()){
            //we did not find any element greater than the arr[i]
			ans[i] = -1 ;
		}

		else{
            //we found the element with greater value
			ans[i] = st.top() ;
		}

        //push the arr[i] in the stack 

		st.push(arr[i]) ;
	}

	return ans ;
}