// https://www.youtube.com/watch?v=R6uoSjZ2imo&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=54
// figure the number of scc - strongly connected components
// print the scc
//  gfg - https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo
// codestudio - https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151
//  strongly connected components are only valid for directed graphs
/* strongly connected components are those components in which
each nodes are reachable to one another*/
// kosaraju algorithm
/* intuition is that each node of scc is reachable by every other
 node so we will reverse all the edges of the graph so that the we
 can perform dfs on individual component and find the number of scc.
 The dfs will not reach other nodes if it does not belong to scc as all
 the nodes are reversed */
 #include <bits/stdc++.h>
void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfs(it, adj, visited, st);
        }
    }

    st.push(node);
}
void dfsN(int node, vector<int> adj[], vector<int> &visited)
{
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            dfsN(it, adj, visited);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // creating the graph
    // vector<int> adj[v];
    // for (auto it : edges)
    // {
    //     int i = it[0];
    //     int j = it[1];
    //     adj[i].push_back(j);
    // }
    // sorting the graph on the basis of finishing time , i.e , use stack and dfs to find the node on which the dfs ends last
    stack<int> st; // this will store all the nodes with sorted finishing time
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }
    // reverse the graph
    vector<vector<int>> adjT[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (auto it : adj[i])
        {
            // i -> it
            // it -> it
            adjT[it].push_back(i);
        }
    }

    // doing the dfs on the reversed graph on the basis of the stack that stores the sorted values
    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!visited[node])
        {
            dfsN(node, adj, visited);
            cnt++;
        }
    }
    return cnt;
}

/*
algorithm
-sort all the edges on the basis of finishing time
-reverse the graph
-do the dfs
*/