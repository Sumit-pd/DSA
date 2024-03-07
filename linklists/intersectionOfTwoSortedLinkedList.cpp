#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/
      
Node* intersect_ll(Node* L1, Node *L2){

    unordered_map<int,int> mp ;
    while(L1 != NULL){
        mp[L1->data]++;
        L1 = L1-> next ;
    }
    Node * dummy = new Node(0) ;
    Node * temp = dummy ;
    while(L2 != NULL){
        if(mp[L2->data] > 0 ){
            Node * newNode = new Node(L2->data) ;
            temp -> next = newNode ;
            temp = temp -> next ;
            mp[L2->data]--;
        }
        L2 = L2 -> next ;
    }
    return dummy -> next ;
}


Node* intersect_ll(Node* L1, Node *L2){

    Node * dummy = new Node(1) ;
    Node * temp = dummy ;
    while(L1 != NULL && L2 != NULL){
        if(L1-> data == L2 -> data){
            Node * newNode = new Node(L1->data) ;
            temp -> next = newNode ;
            temp = temp -> next ;
            L1 = L1 -> next ;
            L2 = L2 -> next ;
        }
        else if(L1-> data < L2 -> data){
            L1 = L1 -> next ;
        }
        else{
            L2 = L2 -> next ;
        }
    }
    return dummy -> next ;
}