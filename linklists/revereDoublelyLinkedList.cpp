Node* reverseDLL(Node* head)
{   
    Node * prev = head -> prev ;
    Node * cur = head ;
    while(cur != NULL) {
        Node * next = cur -> next ;
        cur -> next = prev ;
        cur -> prev = next ;
        prev = cur ;
        cur = next ;
        if(next != NULL){
            next = next -> next ;
        }
    } 
    return prev ;
}
