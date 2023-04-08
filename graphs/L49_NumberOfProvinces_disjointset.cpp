//gfg = https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces 
// this is already solved using traversal techniques but this will be solved using disjoint set data structure so that the topic becomes strong
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

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        Disjoint_set ds(V) ;
        for(int i = 0 ; i < V ; i++ ){
            for(int j = 0 ; j < V ; j++ ){
                if(adj[i][j] == 1 ){
                    ds.unionBySize(i,j) ;
                }
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < V ; i++ ){
            if(ds.findParent(i) == i ){
                cnt++ ;
            }
        }
        return cnt ;
    }
};