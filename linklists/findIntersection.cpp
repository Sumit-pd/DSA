Node* findIntersection(Node *firstHead, Node *secondHead)
{
    while(firstHead != NULL ){
        Node * temp = secondHead ;
        while(temp != NULL ){
            if(temp == firstHead){
                return temp;
            }
            temp = temp -> next ;
        }
        firstHead = firstHead -> next ;
    }
    return NULL ;
}
//using hashing
#include <bits/stdc++.h>
Node* findIntersection(Node *firstHead, Node *secondHead)
{

    unordered_set<Node *> mp ;
    while(firstHead != NULL ){
        mp.insert(firstHead);
        firstHead = firstHead -> next ;
    }
    while(secondHead != NULL ){
        if(mp.find(secondHead) != mp.end()){
            return secondHead ;
        }
        secondHead = secondHead -> next ;
    }
    return NULL ;
}
int findDifference(Node *firstHead, Node *secondHead){
    int ll1 = 0 ;
    int ll2 = 0 ;
    while (firstHead != NULL || secondHead != NULL )
    {
        if(firstHead != NULL ){
            ll1++ ;
            firstHead = firstHead -> next ;
        }
        if(secondHead != NULL ){
            ll2++ ;
            secondHead = secondHead -> next ;
        }
    }
    return ll1 - ll2 ;
}
Node* findIntersection(Node *firstHead, Node *secondHead)
{

    int diff = findDifference(firstHead , secondHead) ;
    if(diff < 0 ){
        // secondList is larger
        while (diff != 0)
        {
            secondHead = secondHead -> next;
            diff++;
        }
    }
    else{
        while (diff != 0)
        {
            firstHead = firstHead -> next ;
            diff-- ;
        }
    }

    while (firstHead != NULL && secondHead != NULL)
    {
        if (firstHead == secondHead)
        {
            return firstHead ;
        }
        firstHead = firsthead -> next ;
        secondHead = secondHead -> next ;
        
    }
    return NULL;
}

Node* findIntersection(Node *firstHead, Node *secondHead){
    Node * temp1 = firstHead ;
    Node * temp2 = secondHead ;
    while (temp1 != temp2)
    {
        if(temp1 == NULL){
            temp1 = firstHead ;
        }
        if (temp2 != secondHead)
        {
            temp2 = secondHead ;
        }
        temp1= temp1->next;
        temp2= temp2->next;
    }
    return temp1 ; 
    
}