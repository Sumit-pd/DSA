#include <bits/stdc++.h> 
int minimumCostTreeFromLeafNodes(vector<int> &arr){
	priority_queue<int,vector<int>,greater<int>> pq ;
	for(auto it : arr){
		pq.push(it) ;
	}
	int ans = 0 ;
	while(pq.size() > 1){
		int first = pq.top() ;
		pq.pop() ;
		int second = pq.top() ;
		pq.pop() ;
		pq.push(first*second) ;
		ans += (first*second) ;
	}
	return ans;
}