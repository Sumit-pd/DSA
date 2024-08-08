int findPower(int n,int x){
    if(n == 0 ) return 0 ;
    if(x == 0) return 1 ;

    int smallAns = findPower(n,x/2) ;

    if(x%2 == 0){
        return smallAns * smallAns ;
    }
    else{
        return smallAns * smallAns * n ;
    }
}