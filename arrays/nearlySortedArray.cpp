#include <bits/stdc++.h> 
vector < int > nearlySorted(vector < int > arr, int n, int k) {
    priority_queue<int,vector<int>,greater<int>> pq ;
    vector<int> ans ;
    for(auto it : arr){
        if(pq.size() > k){
            int val = pq.top() ;
            pq.pop() ;
            ans.push_back(val) ;
        }
        pq.push(it) ;
    }
    while(!pq.empty()){
        int val = pq.top() ;
        pq.pop() ;
        ans.push_back(val) ;
    }
    return ans ;
}
