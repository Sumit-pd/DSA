/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
	if(head == NULL && head -> next == NULL){
		return head ;
	}
    Node * tail = head ;
	int n = 1 ;
	while(tail -> next != NULL){
		tail =tail -> next ;
		n++ ;
	}
	if(k>n){
		k = k % n ;
	}if(n == k || k == 0 ){
		return head ;
	}
	int i = 0 ;
	Node * temp = head ;
	while(i<n-k-1){
		temp = temp -> next ;
		i++ ;
	}
	tail -> next = head ;
	Node * newHead = temp -> next ;
	temp ->  next = nullptr ;
	return newHead ;
}