// the use of circular arrays

#include <bits/stdc++.h> 
class Queue {
    int cnt = 0 ;
    int * arr ;
    int frt = 0 ; // this will be for accessing the front pointer and deletion of the member
    int rear = 0 ; // this will be for pushing the element in the array
    int n ; // this will be the capacity of the queue ie the max element
public:
    Queue(int size = 5000 ) {
        arr = new int[size] ;
        n = size ;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return cnt == 0 ;
    }

    void enqueue(int data) {
        if(cnt == n){
            return ;
        }
        arr[rear % n] = data ;
        rear++ ;
        cnt++ ; 

    }

    int dequeue() {
        if(cnt == 0 ) return -1 ;
        int val = arr[frt%n] ;
        arr[frt%n] = -1 ;
        frt++ ;
        cnt--;
        return val;
    }

    int front() {
        if(cnt == 0 ) return -1 ;
        return arr[frt] ;
    }
};