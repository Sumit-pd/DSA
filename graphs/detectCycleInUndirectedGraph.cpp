#include<bits/stdc++.h>
bool bfs(vector<int> adjist[] , int src , vector<int> &visited){

 	queue< pair<int,int> > q ;
	q.push({src,-1}) ;
	visited[src] = 1 ;
	while(q.size()){
		int node = q.front().first ;
		int parent = q.front().second ;
		q.pop() ;
		visited[node] = 1 ;
		for(auto it : adjist[node]){
			if(!visited[it]){
				q.push({it,node}) ;
			}
			else if(it != parent ){
				return true ;
			}
		}
	}

	return false ;
}
bool dfs(vector<int> adjist[] , int src , int parent , vector<int> &visited ){
	visited[src] = 1 ;
	for(auto it : adjist[src] ){
		if(!visited[it]){
			if(dfs(adjist,it,src,visited) == true ){
				return true ;
			}
		}
		else if(it != parent ){
				return true ;
		}
	}
	return false ;
}
string cycleDetection (vector<vector<int>>& edges, int v, int m)
{
    vector<int> adjist[v+1] ;

	for(auto it : edges ){
		int u = it[0] ;
		int v = it[1] ;
		adjist[u].push_back(v) ;
        adjist[v].push_back(u) ;
	}


	vector<int> visited(v+1,0) ;

	 for(int i = 1 ; i <= v ; i++ ){
		if(visited[i] == 0 ){
			 if(bfs(adjist,i,visited) == true ){
				return "Yes" ;
			}
		}
	 }

	return "No" ;
}
