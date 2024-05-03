void dfs(int src , vector<int> adj[] , vector<int> &visited , vector<int> &ans ){
    if(visited[src] == 1 ) return ;
    visited[src] = 1 ;
    ans.push_back(src) ;
    for(auto it : adj[src] ){
        if(!visited[it]){
            dfs(it,adj,visited,ans) ;
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
     // creating a adjacency list
     vector<int> adj[V] ;
     for(auto it : edges ){
         int u = it[0] ;
         int v = it[1] ;
         adj[u].push_back(v) ;
         adj[v].push_back(u) ;
     }

    vector<int> visited(V,0) ;
     vector<vector<int>> completeAns ;
     for(int i = 0 ; i < V ; i++ ){
         if(!visited[i] ){
             vector<int> smallAns ;
             dfs(i,adj,visited,smallAns) ;
             completeAns.push_back(smallAns) ;
         }
     }
     return completeAns ;
}