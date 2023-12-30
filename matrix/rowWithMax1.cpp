//brute
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int maxi = 0 ;
    int index = -1;
    for(int i = 0 ; i < n ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < m ; j++ ){
            if(matrix[i][j] == 1){
                count++;
            }
        }
        if(maxi < count){
            maxi = count;
            index = i ;
        }
    }
    return index ;
    //O(m*n)
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int row = -1 ;
    int maxi = 0 ;
    for(int i = 0 ; i < n ; i++){
        int cnt = m - (upper_bound(matrix[i].begin(), matrix[i].end(), 0) - matrix[i].begin());
        if(maxi < cnt){
            maxi = cnt ;
            row = i ;
        }
    }
    return row ;
}
//O(nlogm)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int r = 0 ;
    int c = m -1 ;
    int ans = -1 ;
    while(r < n && c >= 0){
        if(matrix[r][c] == 1){
            ans = r ;
            c--;
        }
        else r++;
    }
    return ans ;
    //O(m+n)
    
}
