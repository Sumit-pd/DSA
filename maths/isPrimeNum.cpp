#include<iostream>
using namespace std ;
int main()
{
    int num = 10;

    for(int i = 2 ; i <= sqrt(num) ; i++ )
    {
        if(num % i == 0)
        {
            cout<<"This is not a prime num" ;
        }
    }
    return 0 ;
}