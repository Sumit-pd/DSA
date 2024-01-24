#include <bits/stdc++.h> 
int mod = (1e9+7);
vector < int > productPuzzle(vector < int > & arr, int n) {
    vector<int> left(n,0) ;
    left[0] = 1 ;
    for(int i = 1 ; i < n ; i++ ){
        // left[i] =(int)((long)(left[i-1] * arr[i-1]) % mod) ;
        left[i] = (int)((long long) ((long long)left[i-1] *(long long)arr[i-1]) % mod );
    }

    vector<int> right(n,0) ;
    right[n-1] = 1;
    for(int i = n -2 ; i >= 0 ; i-- )
    {
        right[i] =(int)((long long)((long long)right[i+1] *(long long) arr[i+1]) % mod) ;
        // right[i] = (right[i+1] * arr[i+1] % mod ) ;
    }
    vector<int> ans(n) ; 
    for(int i = 0 ; i < n ; i++ )
    {
        ans[i] = (int)((long long)((long long)left[i] * (long long)right[i]) % mod) ;
    }
    return ans;
}
