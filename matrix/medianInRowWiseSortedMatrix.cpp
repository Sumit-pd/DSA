#include<bits/stdc++.h>
int blackBox(vector<vector<int>> matrix , int n ,int target){
    int cnt = 0 ;
    //finding all the element smaller than equal to target
    for(int i = 0 ; i < n ; i++ ){
        cnt += upper_bound(matrix[i].begin(),matrix[i].end(),target) - matrix[i].begin();
    }
    return cnt ;
}
int median(vector<vector<int>> &matrix, int n, int m) {
    int low = INT_MAX ;
    int high = INT_MIN;
    for(int i = 0 ; i < n ; i++ ){
        low = min(low , matrix[i][0]); // first column 
        high = max(high , matrix[i][m-1] ); // last colums
    }
    while (low <= high)
    {
        int mid = (low + high)/2;
        int elementsSmallerMid = blackBox(matrix,n,mid);
        if(elementsSmallerMid <= ((n*m)/2) ){
            low = mid + 1 ;
        }
        else{
            high = mid - 1 ;
        }
    }
    return low ;
    
}
