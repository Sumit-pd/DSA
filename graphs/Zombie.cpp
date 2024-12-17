int findAns(vector<pair<int,int>> &arr , int k){
    vector<pair<int,int>> directions = {} ;
    unordered_map< pair<int,int>,set<int>> visited ;
    queue<tuple<int,int,int,int>> q ;
    // x , y , days , varientId 
    for(int i = 0 ; i < arr.size() ; i++ ){
        int x = arr[i].first ;
        int y = arr[i].second ;
        q.push({x,y,0,i}) ;
        visited[{x,y}].insert(i) ;
    }

    while(q.size()){
        auto [x,y,days,id] = q.front() ;
        q.pop() ;
        if(visted[{x,y}].size() >= k){
            return days ;
        }

        for(auto [dx,dy] : directions){
            int nx = x + dx ;
            int ny = y + dy ;
            if(isValid(nx,ny) && visited[{nx,ny}].find(id) == visited[{nx,ny}].end()){
                visited[{nx,ny}].insert(i) ;
                q.push({nx,ny,days+1,i}) ;
            }
        }
    }
    return -1 ;
}