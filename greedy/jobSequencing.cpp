#include <bits/stdc++.h>
bool cmp(vector<int> &a , vector<int> &b){
    return a[2] > b[2] ;
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(),jobs.end(),cmp) ;
    int maxi = 0 ;
    int profit = 0 ;
    int cnt = 0 ;
    for(auto it : jobs){
        maxi = max(maxi,it[1]) ;
    }
    vector<int> ans(maxi+1,-1) ;

    

    for(auto it : jobs){
        for(int j = it[1] ; j> 0 ; j-- ){
            if(ans[j] == -1){
                ans[j] = it[0] ;
                profit += it[2] ;
                cnt++;
                break ;
            }
        }
    }
    return {cnt,profit} ;
}



