vector<vector<int>> KClosestPoints(vector<vector<int>> arr , int k ){
    priority_queue< pair<int,vector<int>> > pq ;
    int ans = 0;
    for(auto it : arr){
        int distanct = (it[0] * it[0]) + (it[1] * it[1]) ; 
        if(pq.size() < k ){
            pq.push({distanct,it}) ;
        }
        else{
            if(distanct < pq.top().first){
                pq.pop() ;
                pq.push({distanct,it}) ;
            }
        }
    }

    vector< vector<int> > ans ;
    while(pq.size()){
        ans.push_back(pq.top().second) ;
        pq.pop() ;
    }
    return ans ;
}