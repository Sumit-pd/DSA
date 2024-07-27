#include<stack>
using namespace std ;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node *> st ;
        Node * temp = head ;
        while(temp){
            if(temp -> child){
                // if there is a child that should coming to next of the temp
                if(temp -> next){
                    // if there is node next to it then the node should be kept in the stack as it will be added in the last 
                    st.push(temp -> next) ;
                    temp -> next -> prev = NULL ;
                }
                temp -> next = temp -> child ;
                temp -> child -> prev = temp ;
                temp -> child = NULL ;
            }
            if(!temp -> next && st.size()){
                Node * top = st.top() ;
                st.pop() ;
                temp -> next = top ;
                top -> prev = temp ;
            }
            temp = temp -> next  ;
        }
        return head ;
    }
};