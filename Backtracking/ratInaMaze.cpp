#include <bits/stdc++.h> 
bool isSafe(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &visited , int n ){  
    if ( ( i < n && i >= 0) && (j < n && j >= 0 ) && visited[i][j] != 1 && arr[i][j] == 1 ) {
        return true ;
    }
    return false ;
}


void helper(int i , int j , vector<vector<int>> &arr , vector<vector<int>> &visited , string ans , int n  , vector<string> &test){

    if(i == n-1 && j == n-1 ){
        test.push_back(ans) ;
        return ;
    }
    //DLRU

    visited[i][j] = 1 ;

    //down
    if(isSafe(i+1,j,arr,visited,n)){
        helper(i+1,j,arr,visited,ans+"D",n,test) ;

    }

    //left 
    if(isSafe(i,j-1,arr,visited,n)){
        helper(i,j-1,arr,visited,ans + "L" ,n,test) ;
    }

    //right
    if(isSafe(i,j+1,arr,visited,n)){
        helper(i,j+1,arr,visited,ans+"R",n,test) ;
    }

    //up
    if(isSafe(i-1,j,arr,visited,n)) {
        helper(i-1,j,arr,visited,ans+"U",n,test) ;
    }


    visited[i][j] = 0 ;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<vector<int>> visited(n,vector<int>(n,0)) ;
    vector<string> test ;
    string path = "" ;
    if(arr[0][0] == 0 ){
        return test ;
    }
    helper(0,0,arr,visited,path,n,test) ;
    return test ;
}