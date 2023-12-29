// extreme brute
bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// better
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] <= target && mat[i][m - 1] >= target)
        {
            bool smallAns = binary_search(mat[i].begin(), mat[i].end(), target);
            if (smallAns)
            {
                return true;
            }
        }
    }

    return false;
}
bool searchMatrix(vector<vector<int>>& mat, int target) {
       int n = mat.size();
       int m = mat[0].size() ;
       int i = 0 ; 
       int j = m-1;
       while(i<n && j >=0 ){
              if(mat[i][j] == target){
                     return true ;
              }
              else if(mat[i][j] > target){
                     j--;
              }
              else{
                     i++;
              }
       }
       return false ;
}
// optimal

bool searchMatrix(vector<vector<int>>& mat, int target) {
       int n = mat.size();
       int m = mat[0].size() ;
       int low = 0 ;
       int high = (m*n)-1 ;
       while(low <= high){
              int mid = (low +high)/2 ;
              int i = mid/m ;
              int j = mid%m ;
              if(mat[i][j] == target){
                     return true ;
              }
              else if(mat[i][j] > target){
                     high = mid-1 ;
              }
              else{
                     low = mid + 1;
              }
       }
       return false ;

}

