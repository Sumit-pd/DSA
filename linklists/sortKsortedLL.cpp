// ye mat kar dena warna interviewer bhaga dega
Node *sortedDll(Node *head, int k)
{
    multiset<int> st ;
    Node * temp = head ;
    while(temp != NULL){
        st.insert(temp ->data) ;
        temp = temp -> next ;
    }
    Node * dummy = new Node(0) ;
    temp = dummy ;
    for(auto it : st){
        temp -> next = new Node(it) ;
        temp = temp -> next ;
    }
    return dummy -> next ;
}


#include<bits/stdc++.h>
using namespace std ;
class cmp {
public:
    bool operator()(Node *a, Node *b)
    {
        if (a == NULL) {
            return false;
        }

        if (b == NULL) {
            return true;
        }

        return (a->data > b->data);
    }

};
Node *sortedDll(Node *head, int k)
{
    int i = 0 ;
    priority_queue<Node *,vector<Node*>,cmp> pq ;
    Node * newHead = NULL ;
    Node * cur = head ;
    while(head != NULL && i <= k ){
        //pushing k+1 elements in the pq
        pq.push(head) ;
        head = head -> next ;
        i++ ;
    }
    while(!pq.empty() ){
        if(newHead == NULL){
            newHead = pq.top() ;
            pq.pop() ;
            newHead -> prev = NULL ;
            cur = newHead ;
        }
        else{
            cur -> next = pq.top() ;
            pq.top() -> prev = cur ;
            cur = cur ->next;
            pq.pop() ;
        }
        if(head!=NULL){
            pq.push(head) ;
            head = head -> next ;
        }
    }
    cur -> next = NULL ;
    return newHead ;
    
}
