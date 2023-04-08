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
vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    Disjoint_set ds(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < accounts[i].size(); i++)
        {
            // we are starting with 1 because the 0th index stores the name and we only need the mails
            string mail = accounts[i][j];
            if (mp.find(mail) != mp.end())
            {
                mp[mail] = i;
                // this ensures that the new data with new node gets inserted in the map
            }
            else
            {
                ds.unionBySize(i, mp[mail]) ;
            }
        }
    }
    vector<string> mergedMail[n] ;
    for(auto it : mp ){
        string mail = it.first ;
        int node = ds.findParent(it.second) ;
        mergedMail[node].push_back(mail) ;
    }
    vector<vector<string>> ans ;
    for(int i = 0 ; i < n ; i++ ){
        // checking if the row is empty or not 
        if(mergedMail[i].size() == 0 ) continue;
        // sorting the row as the question needs the sorted row
        sort(mergedMail[i].begin() , mergedMail[i].end() ) ;
        vector<string> temp ;
        temp.push_back(accounts[i][0]) ;
        //pushing the names in the array
        for(auto it : mergedMail[i] )
        {
            temp.push_back(it) ;
        }
        ans.push_back(temp) ;
    }
    return ans ;
}