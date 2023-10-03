/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
//brute
Node* removeKthNode(Node* head, int K)
{
    int n = 0 ;
    Node * temp = head ;
    while(temp != NULL ){
        n++;
        temp = temp ->next ;
    }
    int val = n - K ;
    if(val == 0 ){
        return head -> next ;
    }
    temp = head ;
    int cnt = 1 ;
    while(temp != NULL && cnt < val){
        cnt++ ;
        temp = temp -> next ;
    }
    Node * next = temp -> next ;
    temp -> next = temp -> next -> next ;
    return head ;
}
Node* removeKthNode(Node* head, int K)
{
    Node * dummy = new Node() ;
    dummy -> next = head ;
    Node * slow = dummy ;
    Node * fast = dummy ;
    Node * temp = head ;
    int n = 0 ;
    while(n<K){
        fast = fast -> next ;
        n++;
    }
    while(fast -> next != NULL){
        slow = slow -> next ;
        fast = fast -> next ;
    }
    slow-> next = slow -> next -> next ;
    return dummy-> next ;
}