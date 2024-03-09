#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the DLLNode class:

    class DLLNode {
    public:
	int data;
	Node *next;

	DLLNode(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
}

*****************************************************/

DLLNode* rotateDLL(DLLNode* head, int k) 
{
	if(head == NULL || head -> next == NULL){
		return head ;
	}
    DLLNode * tail = head ;
	int len = 1 ;
	while(tail -> next != NULL){
		tail = tail -> next ;
		len++ ;
	}

	if(len < k ){
		k = k % len ;
	}
	if(k == 0 || k == len ){
		return head ;
	}
	tail -> next = head ;
	head ->prev = tail ;
	int cnt = 1 ;

	while(cnt < len - k ){
		tail = tail -> prev ;
		cnt++;
	}
	tail -> prev -> next = NULL ;
	tail -> prev = NULL ;
	return tail ;
}