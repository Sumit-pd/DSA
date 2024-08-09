vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans ;
    vector<int> visited(n,0) ;
    visited[0] = 1 ;
    queue<int> q ;
    q.push(0) ;
    while(q.size()){
        int node = q.front() ;
        q.pop() ;
        ans.push_back(node) ;
        for(auto it : adj[node] ){
            if(!visited[it]){
                visited[it] =1 ;
                q.push(it) ;
            }
        }
    }
    return ans ;
}


//using the character
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void bfs(char src , unordered_map<char,bool> &visited, map<char,vector<char>> &adj,int des){
    queue<char> q ;
    q.push(src) ;
    visited[src] = true ;
    while(q.size()){
        char top = q.front() ;
        q.pop() ;
        cout<< top << " " ;
        for(auto it : adj[top]){
            if(visited[it] == false){
                visited[it] = true ;
                q.push(it) ;
            }
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
            bfs(it.first,visited,adj) ;
        }
    }

    return 0;
}