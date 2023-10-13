bool isPalindrome(LinkedListNode<int> *head) {
    Node * dummy = NULL ;
    Node * next = head -> next ;
    while (next != NULL)
    {
        head -> next = dummy ;
        dummy = head ;
        head = next;
        next = next -> next ;
    }
    head -> next = dummy ;
    return head ;
}