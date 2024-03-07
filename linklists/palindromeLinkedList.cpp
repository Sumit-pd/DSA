// time complexity : O(2N)
// space complexity : O(N)

#include<bits/stdc++.h>
bool isPalindrome(Node *head)
{
    Node * temp = head ;
    stack<Node * > st ; 
    while(temp != NULL ){
        st.push(temp) ;
        temp = temp -> next ;
    }
    temp = head ;
    while(temp != NULL){
        Node * checkNode = st.top() ;
        st.pop() ;
        if(checkNode -> data != temp -> data ){
            return false ;
        }
        temp = temp -> next ;
    }
    return st.empty() ;
}


// time complexity = O(n)
// space complexity = O(1)

Node* reverseLinkedList(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
bool isPalindrome(Node *head)
{
    Node * slow = head ;
    Node * fast = head -> next ;
    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next ;
        fast = fast ->next -> next ;
    }
    Node * newHead = reverseLinkedList(slow -> next) ;
    Node * newHead1 = newHead ;
    Node * temp = head ;
    while(newHead != NULL){
        if(newHead -> data != temp -> data){
            return false ;
        }
        newHead = newHead -> next ;
        temp = temp -> next ;
    }

    reverseLinkedList(newHead1);
    return true ;

}
