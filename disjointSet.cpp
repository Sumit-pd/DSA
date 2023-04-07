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
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges ;
        for(int i = 0 ; i < V ; i++){
            for(auto it : adj[i]){
                int node = it[0] ;
                int wt = it[1] ;
                edges.push_back({wt, {i,node}}) ;
            }
        }
        sort(edges.begin(), edges.end() )  ;
        Disjoint_set ds(V) ;
        int sum = 0 ;
        for(auto it : edges ){
            int wt = it.first ;
            int u = it.second.first ;
            int v = it.second.second ;
            if(ds.findParent(u) != ds.findParent(v) ){
                sum += wt ;
                ds.unionBySize(u,v) ;
            }
        }
        return sum ;
        
    }
};