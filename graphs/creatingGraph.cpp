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