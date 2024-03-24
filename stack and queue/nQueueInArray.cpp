#include <bits/stdc++.h> 
class NQueue{
    int * arr ;
    int * front ;
    int * rear ;
    int * next ;
    int freespace ;
public:
    // Initialize your data structure.
    NQueue(int n, int s){
        arr = new int[s] ;
        next = new int[s] ;
        for(int i = 0 ; i < n ;i++ ){
            next[i] = i+1 ;
        }
        next[s-1] = -1 ;

        front = new int[n] ;
        rear = new int[n] ;
        for(int i = 0 ; i < n ; i++ ){
            front[i] = -1 ;
            rear[i] = -1 ;
        }

        freespace = 0 ;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespace == -1 ){
            //overflow condition
            return false ;
        }

        int ind = freespace ;
        freespace = next[freespace] ;

        if(front[m-1] == -1 ){
            //this is the first elem
            front[m-1] = ind ;
        }
        else{
            //link the element to its next for it need during the poping
            next[rear[m-1]] = ind ;
        }

        next[ind] = -1 ;

        arr[ind] = x ;

        rear[m-1] = ind ;

    return true ;

    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1] == -1 ){
            return -1 ;
        }

        int ind = front[m-1] ;
        front[m-1] = next[ind] ; // moving to the next index
        next[ind] = freespace ;
        freespace = ind ;
        return arr[ind] ;
    }
};
