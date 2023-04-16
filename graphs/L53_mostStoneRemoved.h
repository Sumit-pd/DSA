// gfg : https://practice.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-stone-removal
// L53 : https://www.youtube.com/watch?v=OwMNX8SPavM&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=53
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
    int maxRemove(vector<vector<int>>& stones, int n) {
      int maxR = 0 ;
      int maxC = 0 ;
      // the stones are stored in the form of {i,j} as i as rowno and j as colno and we will traverse till we find the highest value of each of them
        for(auto it : stones ){
          maxR = max(maxR , it[0]) ;
          maxC = max(maxC , it [1]) ;
        }
        // we need only the nodes involved in the disjoint set data structure so that the nodes that involves having a parent are involved , so we are using map data structure 
        unordered_map<int,int> stonesData ;
        Disjoint_set ds(maxC + maxR + 1) ;
        for(auto it : stones ){
          int rowNode = it[0] ;
          int colNode = it[1] + maxR + 1 ;
          ds.unionBySize(rowNode , colNode) ;
          stonesData[rowNode] = 1 ;
          stonesData[colNode] = 1 ;
        }
        int cnt = 0 ;
        // we are counting the number of components
        for(auto it : stonesData ){
          // now we need to find the ultimate parent of the nodes so that we can find the number of components
          if(ds.findParent(it.first) == it.first ){
            cnt++ ;
          }
        }
        return n - cnt ;
    }
};






/*
-we can only remove a stone if it shares a row or column with some other stone
-we will be treating rows as nodes in the disjoint set , and columns as the next set
- row nodes will be normal but for column we will be using the formula col + m + 1
-we are connecting the rows and columns
*/