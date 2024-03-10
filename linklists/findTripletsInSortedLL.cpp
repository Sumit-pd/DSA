#include <bits/stdc++.h> 
/***********************************************

    Following is the class structure of the Node class:

    class DLLNode
    {
        public:
        int data;
        DLLNode *next;
        DLLNode *prev;
    };

***********************************************/

int countTriplets(DLLNode* head, int x)
{
    DLLNode * p = head ;
    DLLNode * q = head ;
    while(q -> next != NULL){
        q = q -> next ;
    }

    int cnt = 0 ;


    while(p != q && q -> next != p ){
        DLLNode * l = p -> next ;
        DLLNode * r = q ;
        while( l != r && r -> next != l ){
            int sum = p -> data + l -> data + r -> data ;
            if(sum == x ){
                cnt++ ;
                l = l -> next ;
                r = r -> prev ;
            }
            else if(sum < x){
                l = l -> next ;
            }
            else{
                r = r -> prev ;
            }
        }
        p = p -> next ;
    }
    return cnt;
}  
