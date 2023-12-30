#include <bits/stdc++.h> 
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < i ; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i = 0 ; i < n ;i++){
        int low = 0 ;
        int high = n-1;
        while(low < high){
            swap(matrix[low][i],matrix[high][i]);
            high--;
            low++;
        }
    }
    return matrix ;
}
