/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    if(head == NULL){
        return head ;
    }

    // reverse first k node 
    Node * prev = NULL ;
    Node * cur = head ;
    Node * next = NULL ;
    int count = 0 ;
    while( cur != NULL && count < k ){
        next = cur -> next ;
        cur -> next = prev ;
        prev = cur ;
        cur = next ;
        count++ ;
    }



    // If the last group has < k nodes, reversing it again to get the previous order.
     if (count < k)
    {
        cur = prev;
        prev = NULL;
        next = NULL;
        count = 0;
        while (cur && count < k)
        {

            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }
    }

    
    if(next != NULL){
        head -> next = kReverse(next,k) ;
    }
    return prev ;
}