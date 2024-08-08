void dfs(int src , vector<int> adj[] , vector<int> &visited , vector<int> &ans ){
    if(visited[src] == 1 ) return ;
    visited[src] = 1 ;
    ans.push_back(src) ;
    for(auto it : adj[src] ){
        if(!visited[it]){
            dfs(it,adj,visited,ans) ;
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
     // creating a adjacency list
     vector<int> adj[V] ;
     for(auto it : edges ){
         int u = it[0] ;
         int v = it[1] ;
         adj[u].push_back(v) ;
         adj[v].push_back(u) ;
     }

    vector<int> visited(V,0) ;
     vector<vector<int>> completeAns ;
     for(int i = 0 ; i < V ; i++ ){
         if(!visited[i] ){
             vector<int> smallAns ;
             dfs(i,adj,visited,smallAns) ;
             completeAns.push_back(smallAns) ;
         }
     }
     return completeAns ;
}

// we can use unordered_map<Node*,Bool> for maintaining the visited DS 

//function to print the dfs

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void dfs(char src , unordered_map<char,bool> &visited,map<char,vector<char>> adj){
    if(visited[src] == true) return ;
    visited[src] = true ;
    cout<< src << " " ;
    for(auto it : adj[src]){
        if(visited[it] == false){
            dfs(it,visited,adj) ;
        }
    }
}
int main() {
    // Write C++ code here
    map<char, vector<char>> adj;
    

    adj['A'] = {'B', 'C'};
    adj['B'] = {'A', 'D', 'E'};
    adj['C'] = {'A', 'F'};
    adj['D'] = {'B'};
    adj['E'] = {'B', 'F'};
    adj['F'] = {'C', 'E'};
    
    unordered_map<char,bool> visited ;
    for(auto it : adj){
        visited[it.first] = false ;
    }
    
    for(auto it : adj){
        if(!visited[it.first]){
            dfs(it.first,visited,adj) ;
        }
    }

    return 0;
}


