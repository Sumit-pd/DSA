//reverse a linked list iterative 
Node* reverseLinkedList(Node *head)
{
    Node * prev = NULL ;
    Node * cur = head ;
    while (cur != NULL)
    {
        Node * next = cur -> next ;
        cur -> next = prev ;
        prev = cur ; 
        cur = next ;
    }   
    return prev ;
}

//reverse a linked list using recursion 
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