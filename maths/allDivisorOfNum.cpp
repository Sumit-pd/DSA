#include<iostream>
using namespace std ;

int main()
{
    int n = 10 ;


    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n % i == 0 )
        {
            cout<< i <<endl;
            n/i != 1 && cout<< n/i <<endl;            ;
        }
    }
    
}