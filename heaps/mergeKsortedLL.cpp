/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
#include<bits/stdc++.h>
class cmp{
    public:
    bool operator()(Node* a , Node * b ){
        return a -> data > b -> data ;
    }
};
Node* mergeKLists(vector<Node*> &listArray){
    priority_queue< Node * , vector<Node *> , cmp > pq ;

    for(auto it : listArray ){
        pq.push(it) ;
    }
    Node * dummy = new Node(-1) ;
    Node * temp = dummy ;

    while(pq.size()){
        Node * top = pq.top() ;
        pq.pop() ;
        temp -> next = top ;
        temp = temp -> next ;
        if(top -> next ){
            pq.push(top -> next ) ;
        }
    }
    return dummy -> next ;
}
