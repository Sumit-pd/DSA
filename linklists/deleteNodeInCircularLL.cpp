/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
                int data;
                Node *next;
                Node(int data)
                {
                        this->data = data;
                        this->next = NULL;
                }
        };

*****************************************************************/

Node* deleteNode(Node* head, int key) 
{

    if(head == NULL){
        return NULL ;
    }
    
    if(head -> next == head  ){
        if(head -> data == key ){
                free(head) ;
                return NULL;
        }
        return head ;
    }
    if(head -> data == key ){
            Node * temp = head ;
            while(temp -> next != head){
                temp = temp -> next ;
            }
            temp -> next = head -> next ;
            Node * newHead = head -> next ;
            free(head) ;
            return newHead ;
    }
    else{
        Node * prev = NULL ;
        Node * cur = head -> next ;
        while(cur != head ){
                if(cur -> data == key ){
                        prev -> next = cur -> next ;
                        free(cur) ;
                        return head ;
                }
                prev = cur ;
                cur = cur -> next ;
        }
        return head ;
    }
}
