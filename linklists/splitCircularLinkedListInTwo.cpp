void splitCircularList(Node *head)
{
    Node * slow = head ;
    Node * fast = head->next ;
    while(fast != head && fast -> next != head ){
        slow = slow -> next ;
        fast = fast -> next -> next ;
    }
    if(fast -> next == head ){
        fast -> next = slow -> next ;
    }
    else{
        fast -> next -> next = slow -> next ;
    }
    slow -> next = head ;

}

