//using adjacency list
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<vector<int>> adjList(n) ;


    for(int i = 0 ; i < n ; i++ ){
        adjList[i].push_back(i) ;
    }
    for(auto it : edges ){
        int a = it[0] ;
        int b = it[1] ;
        adjList[a].push_back(b) ;
        adjList[b].push_back(a) ;
    }

    return adjList ;

}
// using adjacency list
#include <iostream>
using namespace std ;
int main() {
    // Write C++ code here
    int n = 5 ;
    int m = 2 ;
    
    int adjMat[n][n] ;
    
    for(int i = 0 ; i < n;  i++ ){
        for(int j = 0 ;  j < n ; j++ ){
            adjMat[i][j] = 0 ;
        }
    }
    
    for(int i = 0 ; i < m ; i++ ){
        int u , v ;
        cin>> u >> v ;
        adjMat[u][v] = 1 ;
        adjMat[v][u] = 1 ;
    }
    
    
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            cout<<adjMat[i][j]<<" " ;
        }
        cout<< endl;
    }

    return 0;
}