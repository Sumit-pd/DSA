#include <bits/stdc++.h>
bool detectCycle(Node *head)
{
	unordered_set<Node*> st ;
    while(head != NULL ){
        if(st.find(head) != st.end() ){
            return true ;
        }
        st.insert(head) ;
        head = head -> next ;
    }
    return false ;
}
bool detectCycle(Node *head)
{
	Node * slow = head ;
    Node * fast = head ;
    while(fast != NULL && fast -> next != NULL && fast -> next -> next != NULL ){
        slow = slow -> next ;
        fast = fast -> next -> next ;
        if(slow == fast){
            return true;
        }
    }
    return false ;
}