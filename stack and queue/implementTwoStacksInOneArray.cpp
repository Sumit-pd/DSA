#include <bits/stdc++.h> 
class TwoStack {
    int * arr ;
    int tos1 ;
    int tos2 ;
    int n ;
public:

    // Initialize TwoStack.
    TwoStack(int s) {
        arr = new int[s] ;
        tos1 = -1 ;
        tos2 = s ;
        this -> n = s ;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(tos1+1 != tos2){
            tos1++ ;
            arr[tos1] = num ;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(tos2 -1 != tos1){
            tos2-- ;
            arr[tos2] = num ;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(tos1 > -1) {
            int elem = arr[tos1] ;
            tos1-- ;
            return elem ;
        }
        else return -1 ;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
       if(tos2 < n){
            int elem = arr[tos2] ;
            tos2++ ;
            return elem ;
       }
       return -1 ;
    }
};
