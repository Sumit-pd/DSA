/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
node* sortTwoLists(node * first, node * second)
{
    node * dummy = new node(-1) ;
    node * temp = dummy ;
    while(first != NULL && second != NULL){
        if(first-> data < second -> data){
            temp -> next = first ;
            first = first -> next ;
            temp = temp -> next ;
        }
        else{
            temp -> next = second ;
            second = second -> next ;
            temp = temp -> next ;
        }
    }
    if(first != NULL){
        temp -> next = first ;
        temp = temp -> next ;
    }
    if(second != NULL ){
        temp -> next = second ;
        temp = temp -> next ;
    }
    return dummy -> next ;
}


node *findMiddle(node *head) {
    node * slow = head ;
    node * fast = head -> next ;
    while(fast != NULL && fast -> next  != NULL ){
        slow = slow -> next ;
        fast = fast -> next->next ;
    }
    return slow ;
}



node* mergeSort(node *head) {
    if(head == NULL || head -> next == NULL) return head ;

    
    node * middle = findMiddle(head) ;
    node * first = head ;
    node * second = middle -> next ;
    middle -> next = NULL ;


    first = mergeSort(first) ;
    second = mergeSort(second) ;
    return sortTwoLists(first,second) ;
    
}

