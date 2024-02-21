/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    if(head == NULL || head -> next == NULL ){
        return head ;
    }
    Node * temp = head ;
    
    while(temp && temp -> next){
        Node * next = temp -> next ;
        while(next && temp -> data == next -> data ){
            Node * duplicate = next ; // thhis is for c++ users to remove the duplicate
            next = next -> next ;
            free(duplicate) ;
        }
        temp -> next = next ;
        if(next){
            next -> prev = temp ;
        }
        temp = temp->next ;
    }
    return head ;
}
