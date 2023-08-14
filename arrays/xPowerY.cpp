//naive
double myPow(double x, int n) {
    return pow(x,n) ;
}

double BetterMyPow(double x, int n) {
    double ans = 1 ;
    long long num = abs(n); // to avoid overflow
    for(int i = 0 ; i< num ;i++ ){
        ans *= x ;
    }
    if(n < 0 ){
        return 1/ans ;
    }
    return ans ;
}


double optimalMyPow(double x, int n) {
    double ans = 1.0 ;
    long long nn = n ;
    if(n < 0 ){
        nn *= -1 ; // converting it into positive number
    }

    while(nn > 0 ){
        if(nn % 2 ){
            ans *= x ;
            nn -= 1 ;
        }
        else {
            x *= x ;
            nn /= 2;
        }
    }
    if(n < 0 ){
        return (double)1.0 /(double) ans ;
    }
    return ans ;
}