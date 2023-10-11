#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    //copy the data of the data of the node -> next to node's data
    node -> data = node -> next -> data ;
    //remove the element next of the node
    node -> next = node -> next -> next ;
}