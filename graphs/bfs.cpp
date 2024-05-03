vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans ;
    vector<int> visited(n,0) ;
    visited[0] = 1 ;
    queue<int> q ;
    q.push(0) ;
    while(q.size()){
        int node = q.front() ;
        q.pop() ;
        ans.push_back(node) ;
        for(auto it : adj[node] ){
            if(!visited[it]){
                visited[it] =1 ;
                q.push(it) ;
            }
        }
    }
    return ans ;
}