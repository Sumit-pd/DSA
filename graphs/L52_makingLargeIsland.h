// https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group
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
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if (ult_u == ult_v)
        {
            return;
        }
        if (size[ult_u] < size[ult_v])
        {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else
        {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution
{
private:
    bool isValid(int i, int j, int n, int m)
    {
        return (i < n && i >= 0 && j < m && j >= 0);
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        Disjoint_set ds(n * n);
        // the following line will add all the components to the
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int dr[4] = {-1, 0, 1, 0};
                    int dc[4] = {0, 1, 0, -1};
                    for (int k = 0; k < 4; k++)
                    {
                        int newR = i + dr[k];
                        int newCol = j + dc[k];
                        if (isValid(newR, newCol, n, n) && grid[newR][newCol] == 1)
                        {
                            ds.unionBySize(i * n + j, newR * n + newCol);
                        }
                    }
                }
            }
        }
        int maxi = 0 ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int dr[4] = {-1, 0, 1, 0};
                    int dc[4] = {0, 1, 0, -1};
                    set<int> st;
                    for (int k = 0; k < 4; k++)
                    {
                        int newR = i + dr[k];
                        int newCol = j + dc[k];
                        if (isValid(newR, newCol, n, n) && grid[newR][newCol] == 1)
                        {
                            st.insert(ds.findParent(newR * n + newCol));
                            // we need to store the its ultimate parent so that the component is only added once
                        }
                    }
                    int sizeTotal = 0;
                    for (auto it : st)
                    {
                        // the set will be storing all the unique components of that needs to be added
                        sizeTotal += ds.size[it] + 1  ; // the extra 1 is for the cell which joins the two components
                    }
                    maxi = max(maxi , sizeTotal) ;
                }
            }
        }
        for (int ind = 0; ind < n * n ; ind++)
        {
            maxi = max(maxi,ds.size[ds.findParent(ind)]) ;
        }
        return ans ;
    }
};