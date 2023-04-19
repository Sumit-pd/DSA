// leetcode - https://leetcode.com/problems/critical-connections-in-a-network/
// codestudio - 
#include <bits/stdc++.h>
/*
-we will take two separate arrays one is time of insertion and lowest time
-we need to keep a track of the step at which the dfs call is reaching a particular node this will be stored in the time array
-lowest time array will store the lowest of all the adjecent nodes time without considering the parent
*/
void dfs(int node, int parent, vector<int> adj[], vector<int> &visited, vector<int> &time, vector<int> &lowest, int &timer, vector<vector<int>> &ans)
{
    visited[node] = 1;
    time[node] = lowest[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (!visited[it])
        {
            dfs(it, node, adj, visited, time, lowest, timer, ans);
            // store the min of the time
            lowest[node] = min(lowest[node], lowest[it]);
            if (lowest[it] > time[node])
            {
                // this will be the bridge
                ans.push_back({it, node});
            }
        }
         else
        {
            // this will not be an bridge
            lowest[node] = min(lowest[node], lowest[it]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, int m, vector<vector<int>> &edges)
{
    vector<int> adj[n + 1];
    // creating a graph
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> time(n + 1);
    vector<int> lowest(n + 1);
    vector<int> visited(n + 1,0);
    int timer = 1;
    vector<vector<int>> ans;
    dfs(1, -1, adj, visited, time, lowest, timer, ans);
    return ans;
}
/*
-lets take a pair of nodes and we need to check if there is bridge {u,v}
-if low[u] > time[v] there is bridge
-intuition: we are not checking the time of the parent because we are hypothetically

*/
