#include<iostream>
using namespace std ;
// brute
int gcd(int n, int m) {
        
    int maxi = 1 ;
    for(int i = min(n,m); i >= 1 ; i-- )
    {
        if( n%i == 0 && m%i == 0 )
        {
            return i ;
        }
    }
    return 1 ;
}

// optimal : equilidian algorithm
int EquliAlgo(int a , int b)
{
    while( a > 0 && b > 0 )
    {
        if( a > b)
        {
            a = a % b ;
        }
        else
        {
            b = b % a ;
        }
    }

    return a != 0 ? a : b ;
}