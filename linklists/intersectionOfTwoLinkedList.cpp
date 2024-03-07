#include<bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node*> st ;
    while(firstHead != NULL){
        st.insert(firstHead) ;
        firstHead = firstHead -> next ;
    }

    while(secondHead != NULL ){
        if(st.find(secondHead) != st.end()){
            return secondHead ;
        }
        secondHead = secondHead -> next ;
    }
    return NULL ;
}


Node* findIntersection(Node *firstHead, Node *secondHead)
{
    Node * temp1 = firstHead ;
    Node * temp2 = secondHead ;
    while(temp1!=temp2){
        temp1 = temp1 -> next ;
        temp2 = temp2 -> next ;
        if(temp1 == NULL ){
            temp1 = secondHead ;
        }
        if(temp2 == NULL){
            temp2 = firstHead ;
        }
    }
    return temp2 ;
}