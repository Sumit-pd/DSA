vector<int> spiralMatrix(vector<vector<int>>&arr) {
    int n = arr.size() ;
    int m = arr[0].size() ;
    vector<int> ans ;
    int left = 0 , right = m - 1 ;
    int top = 0  , bottom = n - 1 ;
    while( left <= right && top <= bottom){
        //left to right 
        for(int i = left ; i <= right ; i++){
            ans.push_back(arr[top][i]) ;
        }
        top++ ;
        //top to bottom
        for(int i = top ; i <= bottom ; i++ ){
            ans.push_back(arr[i][right]) ;
        }
        right-- ;
        // this is a check for avoiding the print of same line if there is only one row
        if(top <= bottom ){
            //right to left
            for(int i = right ; i >= left ; i--){
                ans.push_back(arr[bottom][i]) ;
            }
             bottom-- ;
        }
       
        // checking if there is only one column to void print of same element twice
        if(left <= right ){
            // top to bottom
            for(int i = bottom ; i >= top ; i--){
                ans.push_back(arr[i][left]) ;
            }
            left++ ;
            }
        }
    return ans ;
}
