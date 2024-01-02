//brute
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size() ;
    int ans = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        for(int j = i ; j < n ; j++ ){
            int val = 0 ;
            for(int k = i ; k <= j ; k++ ){
                val = val ^ a[k] ;
            }
            if(val == b){
                ans++  ;
            }
        }
    }
    return ans ;
}
// better 
//