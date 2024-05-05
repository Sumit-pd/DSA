class Solution {
    void dfs(int node , vector<pair<int,int>> adj[] , vector<int> &visited , stack<int> &st ){
    visited[node] = 1 ;
    for(auto it : adj[node] ){
        int v = it.first ;
        if(!visited[v] ){
            dfs(v,adj,visited,st) ;
        }
    }
    st.push(node) ;
}
  public:
     vector<int> shortestPath(int v,int M, vector<vector<int>>& edges){
        vector<int> visited(v,0) ;
        stack<int> st ;
        vector<pair<int,int> > adj[v] ;
        for(auto it : edges ){
            int u = it[0] ;
            int v = it[1] ;
            int w = it[2] ;
            adj[u].push_back({v,w}) ;
        }
        for(int i = 0 ; i < v ; i++ ){
            if(!visited[i]){
                dfs(i,adj,visited,st) ;
            }
        }
        
        vector<int> dist(v,INT_MAX) ;
        dist[0] = 0 ;
        while(st.size()){
            int node = st.top() ;
            st.pop() ;
            for(auto it : adj[node] ){
                if(dist[node] == INT_MAX ){
                    break ;
                }
                int v = it.first ;
                int wt = it.second ;
                dist[v] = min(dist[node] + wt , dist[v]) ;
            }
        }
        
        for(int i = 0 ;i < v ; i++ ){
            if(dist[i] == INT_MAX ){
                dist[i] = -1 ;
            }
        }
        return dist ;
    }
};