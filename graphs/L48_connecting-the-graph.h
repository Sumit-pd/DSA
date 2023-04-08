// gfg = https://practice.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph 
class Disjoint_set
{
public:
    vector<int> rank, parent, size;

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
    int Solve(int n, vector<vector<int>>& edge) {
        Disjoint_set ds(n) ;
        int extraEdges = 0 ;
        int component = 0 ;
        for(auto it : edge ){
            int u = it[0];
            int v = it[1] ;
            if(ds.findParent(u) == ds.findParent(v) ){
                extraEdges++ ;
            }
            else{
                ds.unionBySize(u,v) ;
            }
        }
        for(int i = 0 ; i < n ; i++ ){
            if(ds.parent[i] == i ){
                component++ ;
            }
        }
        int ans = component - 1 ;
        if(extraEdges >= ans){
            return ans ;
        }
        else {
            return -1 ;
        }
        
    }
};