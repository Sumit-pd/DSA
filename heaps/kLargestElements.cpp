#include <bits/stdc++.h> 
vector<int> Klargest(vector<int> &a, int k, int n) {
    vector<int> ans ;
    priority_queue<int,vector<int>,greater<int> > pq ;

    for(int i = 0 ; i < n ; i++ ){
        pq.push(a[i]) ;
        if(pq.size() > k ){
            pq.pop() ;
        }
    }

    for(int i = 0 ; i < k ;i++){
        int elem = pq.top() ;
        pq.pop() ;
        ans.push_back(elem) ;
        
    }
    return ans;
}