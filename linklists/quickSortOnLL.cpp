#include <bits/stdc++.h> 
Node * tail(Node * head){
	while(head -> next != NULL){
		head = head -> next ;
	}
	return head ;
}
Node * partition(Node * head , Node * tail ){
	Node * pivot = head ;
	Node * cur = head -> next ;
	Node * prev = head ;
	while(cur != tail -> next ){
		if(cur -> data < pivot -> data){
			swap(prev -> next -> data , cur -> data) ;
			prev = prev -> next ;
		}
		cur = cur -> next ;
	}
	swap(prev -> data , pivot -> data );
	return prev ;
}
void helper(Node * head , Node * tail){
	if(head == tail || head == NULL ) return ;
	Node * par = partition(head , tail ) ;
	helper(head , par) ;
	helper(par -> next , tail ) ;
}
Node *quickSortLL(Node *head)
{
	if(head == NULL || head -> next == NULL ) return head ;
    Node * t = tail(head) ;
	helper(head,t) ;
	return head ;
}


/*
ALGORITHM
- find the tail of the linkedlist
- now find the partition of the linkedlist
- do a recursion call for head to partition and partition -> next to tail

*/

