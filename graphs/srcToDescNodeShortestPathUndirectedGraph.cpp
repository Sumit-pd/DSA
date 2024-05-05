#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	vector<int> adj[n+1] ;
	for(auto it : edges ){
		int u = it.first ;
		int v = it.second ;
		adj[u].push_back(v) ;
		adj[v].push_back(u) ;
	}

	vector<int> parentArray(n+1) ;

	queue<int> q ;
	parentArray[s] = -1 ;
	q.push(s) ;
	vector<int> visited(n+1,0) ;
	while(q.size()){
		int node = q.front() ;
		q.pop() ;
		for(auto it : adj[node]){
			if(!visited[it]){
				visited[it] = 1 ;
				parentArray[it] = node ;
				q.push(it) ;
			}
		}
	}

	vector<int> ans ;
	int node = t ;
	while(node != s ){
		ans.push_back(node) ;
		node = parentArray[node] ;
	}
	ans.push_back(s) ;
	reverse(ans.begin() , ans.end() ) ;
	return ans ;
	
}
