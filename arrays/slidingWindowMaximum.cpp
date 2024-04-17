#include <bits/stdc++.h> 
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
