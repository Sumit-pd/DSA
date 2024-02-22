#include <bits/stdc++.h> 
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
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{
    unordered_set<int> st ;
    Node * temp = head ; 
    Node * prev = NULL ;
    while(temp){
        if(st.find(temp->data) != st.end()){
            prev-> next = temp-> next;
            temp = temp -> next ;
        }
        else{
            st.insert(temp -> data) ;
            prev= temp ;
            temp = temp -> next ;
        }
    }
    return head ;
}