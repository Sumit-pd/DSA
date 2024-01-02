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

//optimal

#include <bits/stdc++.h> 
int countSmallerThan(vector<vector<int>> &mat, int n , int target ){
    int cnt = 0 ;
    for(int i = 0 ;i < n ; i++){
        cnt += upper_bound(mat[i].begin(),mat[i].end(),target) - mat[i].begin();
    }
    return cnt ;
}
int kSmallestInMatrix(vector<vector<int>> &mat, int k){
    int n = mat.size();
    int low = mat[0][0];
    int high = mat[n-1][n-1];
    while(low <= high){
        int mid = (low + high)/2 ;
        int cnt = countSmallerThan(mat,n,mid);
        if(cnt <= k-1){
            low = mid + 1;
        }
        else{
            high = mid -1 ;
        }
    }
    return low ;
}
