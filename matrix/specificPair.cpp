#include <bits/stdc++.h> 
int findMaxValue(vector<vector<int>>& mat, int n) {
    int maxi = INT_MIN;
	for(int a = 0 ; a < n ; a++){
        for(int b = 0 ; b < n ; b++ ){
            for(int c = a+1 ; c < n ; c++){
                for(int d = b+1 ; d < n ; d++ ){
                    int diff = mat[c][d] - mat[a][b];
                    maxi = max(maxi,diff);
                }
            }
        }
    }  
    return maxi;
}

int findMaxValue(vector<vector<int>>& mat, int n) {
	vector<vector<int>> maxMatrix(n,vector<int>(n,0));
    maxMatrix[n-1][n-1] = mat[n-1][n-1] ;
    for(int i = n-2 ; i >= 0 ; i--){
        maxMatrix[n-1][i] = max(maxMatrix[n-1][i+1],mat[n-1][i]);
    } 
    for(int i = n-2 ; i>=0 ; i--){
        maxMatrix[i][n-1] = max(maxMatrix[i+1][n-1],mat[i][n-1]);
    }


    for(int i = n-2 ; i>= 0 ; i--){
        for(int j = n-2 ; j >= 0 ; j--){
            maxMatrix[i][j] = max(max(maxMatrix[i+1][j],maxMatrix[i][j+1]),mat[i][j]);
        }
    }
    int maxi = INT_MIN ;
    for(int i = 0 ; i < n-1; i++ ){
        for(int j =0 ; j < n-1 ; j++ ){
            int diff = maxMatrix[i+1][j+1] - mat[i][j];
            maxi = max(maxi , diff);
        }
    }
    return maxi ;
}
