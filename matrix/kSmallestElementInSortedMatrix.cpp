#include <bits/stdc++.h> 
int kSmallestInMatrix(vector<vector<int>> &mat, int k){
    priority_queue<int,vector<int>,greater<int>> pq ;
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++ ){
            pq.push(mat[i][j]);
        }
    }
    int ans = -1;
    while(k>0){
        ans = pq.top();
        pq.pop();
        k--;
    }
    return ans;
}
