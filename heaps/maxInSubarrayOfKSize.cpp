//brute
#include <bits/stdc++.h> 
vector<int> maxOfSubarray(vector<int> arr, int n, int k) 
{
	vector<int> ans ;
	for(int i = 0 ; i < n-k+1; i++ ){
		int maxi = 0 ;
		for(int j = i ; j < k + i ; j++ ){
			maxi = max(maxi,arr[j]) ;
		}
		ans.push_back(maxi) ;
	}
	return ans ;
}
//using dequeue
vector<int> maxOfSubarray(vector<int> nums, int n, int k) 
{
	vector<int> ans ;
	deque<int> q ; 

	
	int i = 0 , j = 0 ;

	while(j<n){

		// calculations 
		while(q.size() && q.back() < nums[j]){
			q.pop_back() ;
		}

		q.push_back(nums[j]) ;

		if(j - i + 1 < k ) j++ ;

		else if(j-i+1 == k ){
			ans.push_back(q.front()) ;
			if(nums[i] == q.front()){
				q.pop_front() ;
			}
			i++ ; 
			j++ ;
		}
	}
	return ans ;
	
}

#using smallest#include <bits/stdc++.h> 
vector<int> maxOfSubarray(vector<int> nums, int n, int k) 
{
	 vector<int> ans;
    
    // Set to store the elements and its indices
    set<pair<int, int>> st;
	
    for (int i = 0; i < k; i++) 
    {
        st.insert({nums[i], i});
    }

    ans.push_back((*st.rbegin()).first);
	for(int i = k ; i < n ; i++ ){
		int prev = i - k ;
		st.erase({nums[prev],prev}) ;
		st.insert( {nums[i],i} ) ;
		ans.push_back((*st.rbegin()).first) ;
	}

	return ans ;
}

