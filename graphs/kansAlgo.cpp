#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> indegre(v,0); 
    vector<int> adj[v] ;
    for(auto it : edges ){
        int u = it[0] ;
        int v = it[1] ;
        adj[u].push_back(v) ;
        indegre[v]++ ;
    }

    queue<int> q ;

    for(int i = 0 ; i < v ; i++ ){
        if(indegre[i] == 0 ){
            q.push(i) ;
        }
    }

    vector<int> ans ;
    while(q.size()){
        int top = q.front() ;
        q.pop() ;
        ans.push_back(top) ;
        for(auto it : adj[top] ){
            indegre[it]-- ;
            if(indegre[it] == 0 ){
                q.push(it) ;
            }
        }
    }

    return ans ;
}