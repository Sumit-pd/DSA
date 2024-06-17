int miniNumSwaps(string s, int n) {
    int open = 0 , close = 0 ;
    // whenever we get [ we need to swap till unbalancedClosed times so that we get to the balanced situation
    // it represents number of closed brackets which are unbalanced
    int unbalancedClosed = 0 ; 
    int ans = 0 ;

    for (int i = 0; i < 2*n; i++)
    {
        char ch = s[i] ;
        if (ch == '('){
            open++ ;
            if(unbalancedClosed > 0 ){
                ans += unbalancedClosed ;
                unbalancedClosed-- ;
            }
        }
        else{
            close++ ;
            unbalancedClosed = close - open ;
        }
    }

    return ans ;
    
}