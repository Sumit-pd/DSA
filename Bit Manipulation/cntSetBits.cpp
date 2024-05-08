int helper(int n){
    int cnt = 0 ;
    while(n>0){
        int rem = n%2 ;
        if(rem == 1 ){
            cnt++ ;
        }
        n = n/2 ;
    }
    return cnt ;
}
int countSetBits(int n) {
  int cnt = 0 ;
  for(int i = 1 ; i <= n ;i++ ){
    cnt += helper(i);
  }
  return cnt ;
}


/***************************************************************************************************************************************/

//optimal
int countSetBits(int n) {
  int count = 0;
  for (int i = 1; i <= n; i++)
    count += __builtin_popcount(i);
  return count;
}


/****************************************************************************************************/

/* Bit Manipulation solution */





