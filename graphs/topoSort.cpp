#include <bits/stdc++.h> 
void dfs(int node , vector<int>adj[] , vector<int> &visited , stack<int> &st ){
    visited[node] = 1 ;
    for(auto it : adj[node] ){
        if(!visited[it] ){
            dfs(it,adj,visited,st) ;
        }
    }
    st.push(node) ;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> visited(v,0) ;
    stack<int> st ;
    vector<int> adj[v] ;
    for(auto it : edges ){
        int u = it[0] ;
        int v = it[1] ;
        adj[u].push_back(v) ;
    }
    for(int i = 0 ; i < v ; i++ ){
        if(!visited[i]){
            dfs(i,adj,visited,st) ;
        }
    }

    vector<int> ans ; 
    while(st.size() ){
        ans.push_back(st.top()) ;
        st.pop() ;
    }

    return ans ;
}