#include <bits/stdc++.h> 
bool check(int row , int col , vector<vector<int>> &sudoku , int n , int num ){
    for(int i = 0 ; i < n ; i++ ){
        // checking the current row
        if(sudoku[row][i] == num ){
            return false ;
        }
        // checking the current column 
        if(sudoku[i][col]  == num ){
            return false ;
        }

        //checking the grid

        if(sudoku[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == num ){
            return false;
        }
    }
    return true ;
}
bool helper(vector<vector<int>> &sudoku ){
    int n = sudoku.size() ;
    
    for(int i = 0 ; i < n ; i++ ){
        for(int j = 0 ; j < n ; j++ ){
            if(sudoku[i][j] == 0 ){
                // we need to insert the cells
                for(int num = 1 ; num <= 9 ; num++ ){
                    if(check(i,j,sudoku,n,num)){
                        sudoku[i][j] = num ;
                        if(helper(sudoku)){
                            return true ;
                        }
                        else {
                            // backtrack dusra number dhaal ke dekho
                            sudoku[i][j] = 0 ;
                        }
                    }
                }
                return false ;
            }
        }
    }
}
void solveSudoku(vector<vector<int>>& sudoku)
{
	helper(sudoku) ;
}




