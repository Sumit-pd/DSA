#include<bits/stdc++.h>
bool dfs(int i , vector<int> adj[] , vector<int> &visited , vector<int> &pathVisited ){
	visited[i] = 1 ;
	pathVisited[i] = 1 ;
	for(auto it : adj[i] ){
		if(!visited[it]){
			if(dfs(it,adj,visited,pathVisited) == true ){
				return true ;
			}
		}
		else if( pathVisited[it]  ){
				return true ;
		}
	}
	pathVisited[i] = 0 ;
	return false ;


	
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adjList[v] ;

	for(auto it : edges ){
		int u = it[0] ;
		int v = it[1] ;
		adjList[u].push_back(v) ;
	}

	vector<int> visited(v ,0) ;
	vector<int> pathVisited(v,0) ;
	for(int i = 0 ; i < v ; i++ ){
		if(!visited[i] ){
			if(dfs(i,adjList , visited, pathVisited) == true ){
				return true ;
			}
		}
	}
	return false ;
}


//using bfs
#include <bits/stdc++.h> 
int topologicalSort(vector<int> adj[] ,vector<int> indegre, int v)  {

    queue<int> q ;
    int cnt = 0 ;
    for(int i = 1 ; i <= v ; i++ ){
        if(indegre[i] == 0 ){
            q.push(i) ;
        }
    }

    // vector<int> ans ;
    while(q.size()){
        int top = q.front() ;
        q.pop() ;
        // ans.push_back(top) ;
        cnt++ ;
        for(auto it : adj[top] ){
            indegre[it]-- ;
            if(indegre[it] == 0 ){
                q.push(it) ;
            }
        }
    }

    return cnt ;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adj[n+1] ;
  vector<int> indegre(n+1,0); 
    for(auto it : edges ){
        int u = it.first ;
        int v = it.second ;
        adj[u].push_back(v) ;
        indegre[v]++ ;
    }

    int cnt  = topologicalSort(adj,indegre,n) ;

    if(cnt == n ){
        return 0 ;
    }
    else {
        return 1 ;
    }
}