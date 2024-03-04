/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

//time complexity : O(3N)
//space complexity : O(1)
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
Node *addOne(Node *head)
{
    Node * newHead = reverseLinkedList(head) ;
    Node * temp = newHead ;
    int carry = 1 ;
    while(temp != NULL){
        temp -> data = temp -> data + carry ;
        if(temp -> data < 10 ){
            carry = 0 ;
            break ;
        }
        else{
            temp -> data = 0 ;
            carry = 1 ;
            temp = temp -> next ;
        }
    }
    head = reverseLinkedList(newHead) ;
    if(carry == 0 ){
        return head ;
    }
    Node * CarryHead = new Node(carry) ;
    CarryHead -> next = head ;
    return CarryHead ;
}



//time complexity : O(n), space complexity:O(N)
int helper(Node * head ){
    //this function will do the addition and return the carry 
    if(head == NULL){
        return 1 ;
    }
    int carry = helper(head -> next ) ;
    head -> data = head -> data + carry ;
    if(head -> data < 10 ){
        return 0 ;
    }
    else{
        head -> data = 0 ;
        return 1 ;
    }
}
Node *addOne(Node *head)
{
    // this function will be adding the new node
    int carry = helper(head) ;
    if(carry == 0){
        return head ;
    }
    Node * newHead = new Node(1) ;
    newHead-> next = head ;
    return newHead ;
}