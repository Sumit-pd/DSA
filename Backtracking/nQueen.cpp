#include<iostream>
#include<vector>
using namespace std ;
void add(vector<vector<int>> &ans , vector<vector<int>> &board , int n ){
    vector<int> temp ;
    for(int i = 0 ; i <  n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            temp.push_back(board[i][j]) ;
        }
    }
    ans.push_back(temp) ;
}

bool isSafe(int row , int col , vector<vector<int>> &board, int n){
    int i = row ;
    int j = col ;


    // checking for the column 

    while(i>= 0 ){
        if(board[i][j] == 1 ){
            return false ;
        }
        i--;       
    }

    i = row ;
    j = col ;
    //checking for row
    while(j >= 0 ){
        if(board[i][j] == 1 ){
            return false ;
        }
        j--;
    }

    // checking for the left above diagonal

    i = row ;
    j = col ;
    while( j >= 0 && i >= 0 ){
        if(board[i][j] == 1 ){
            return false ;
        }
        i-- ;
        j-- ;
    }

    i = row ;
    j = col ;

    //checking for the lower diagonal
    while(j>= 0 && i < n ){
        if(board[i][j] == 1 ){
            return false ;
        }
        i++ ;
        j-- ;
    }

    return true ;
}
void helper(vector<vector<int>> &ans , vector<vector<int>> &board , int n ,int col ){
    
    if(col >= n ){
        add(ans,board,n) ;
        return ;
    }

    // for each row of the specified column 
    for(int i = 0 ; i < n ; i++ ){
        if(isSafe( i , col , board,n )){
            board[i][col] = 1 ;
            helper(ans,board,n,col+1) ;
            board[i][col] = 0 ;
        }
    }

}
vector<vector<int>> solveNQueens(int n) {

    vector<vector<int>> ans ;
    vector<vector<int>> board(n,vector<int>(n,0) ) ;
    helper(ans,board,n,0) ;
    return ans  ;

}