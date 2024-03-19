#include <bits/stdc++.h> 
class NStack
{
    int * arr ;
    int * top ;
    int * next ;
    int freespot ;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S] ;
        top = new int[N] ;
        next = new int[S] ;
        for(int i = 0 ; i < N ; i++ ){
            top[i] = -1 ;
        }
        for(int i = 0 ; i < S ; i++ ){
            next[i] = i + 1 ;
        }
        next[S-1] = -1 ;

        freespot = 0 ;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot == -1 ){
            return false ;
        }
        int ind = freespot ;
        arr[ind] = x ;

        freespot = next[freespot] ;


        next[ind] = top[m-1] ;

        top[m-1] = ind ;

        return true ;

        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1 ){
            return -1 ;
        }

        int ind = top[m-1] ;
        top[m-1] = next[ind] ;
        next[ind] = freespot  ;
        freespot = ind ;
        return arr[ind] ;

    }
};