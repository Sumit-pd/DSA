#include<map>
#include<vector>
using namespace std ;
class Graph{
    unordered_map<int,vector<int>> adj ;

    // for undirected graph
    void addEdge(int u , int v){
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    void printGraph(){
        for(auto it : adj)
        {
            cout<< it.first << " " ;
            for(auto adjEdges : it.second){
                cout<< " -> " << adjEdge << endl ;
            }
        }
    }
}