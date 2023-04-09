bool isValid(int i , int j , int n , int m ){
    return (i < n && i >= 0 && j < m && j >= 0 ) ;
}
class Disjoint_set
{
private:
    vector<int> rank, parent, size;

public:
    Disjoint_set(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]); // this is the path compression
    }
    void unionByRank(int u, int v)
    {
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v)
            return;
        if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_u] = ult_v;
        }
        else if (rank[ult_u] < rank[ult_v])
        {
            parent[ult_v] = ult_u;
        }
        else
        {
            parent[ult_u] = ult_v;
            rank[ult_v]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ult_u = findParent(u) ;
        int ult_v = findParent(v) ;
        if (ult_u == ult_v)
        {
            return ;
        }
        if (size[ult_u] < size[ult_v])
        {
            parent[ult_u] = ult_v ; 
            size[ult_v] += size[ult_u] ;
        }
        else{
            parent[ult_v] = ult_u ; 
            size[ult_u] += size[ult_v] ;
        }
    }
}; 


vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	Disjoint_set ds(n * m) ;
    vector<int> ans ;
    int visited[n][m] ;
    memset(visited , 0 , sizeof(visited)) ;
    int cnt = 0 ;
    for(auto it : q ){
        int row = it[0] ;
        int col = it[1] ;
        if(visited[row][col] == 1 ){
            ans.push_back(cnt);
            continue;
        }
        cnt++ ;
        // we will increase the count value every time we iterate
        visited[row][col] = 1 ;
        int dr[4] = {-1,0,1,0} ;
        int dc[4] = {0,1,0,-1} ;
        for (int ind = 0; ind < 4; ind++) {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                if (isValid(adjr, adjc, n, m)) {
                    if (visited[adjr][adjc] == 1) {
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        if (ds.findParent(nodeNo) != ds.findParent(adjNodeNo)) {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
                
            }
        ans.push_back(cnt);
    }
    return ans;
}


