//time complexity : O(2N) 
//space complexity : O(N)
Node* copyRandomList(Node* head) {
    unordered_map<Node*,Node*> hashMap;
    Node* temp = head;
//first iteration for inserting deep nodes of every node in the hashmap.
    while(temp != NULL) {
        Node* newNode = new Node(temp->val);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    Node* t = head;
//second iteration for linking next and random pointer as given question.
    while(t != NULL) {
        Node* node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next]:NULL;
        node->random = (t->random != NULL) ? hashMap[t->random]:NULL;
        t = t->next;
    }
    return hashMap[head];
}


//optimal  solution with time complexity:O(N) & space complexity:O(1).
/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */
void createNodes(Node * head){
	Node * temp = head ;
	while(temp != NULL ){
		Node * cloneNode = new Node(temp -> data ) ;
		cloneNode -> next = temp -> next ;
		temp -> next = cloneNode ;
		temp = temp -> next -> next ;
	}
}
void updateRandom(Node * head){
	Node * temp = head ;
	while(temp != NULL){
		Node * cloneNode = temp -> next ;
		cloneNode -> random = temp -> random != NULL ? temp -> random -> next : NULL ; // the copy of the random will be at its random
		temp = temp -> next -> next ;
	}
}

Node * getDeepCopy(Node * head){
	Node * dummy = new Node(-1) ;
	Node * res = dummy ;
	Node * temp = head ;
	while(temp!=NULL){
		res -> next = temp -> next ; // res will be the clonned linked list
		temp -> next = temp -> next -> next ;
		res = res -> next ;
		temp = temp -> next ;
	}

	return dummy -> next ;
}
Node *cloneLL(Node *head){
	//clone the nodes of the new linked list
	createNodes(head) ;
	//updating the random pointers
	updateRandom(head) ;

	return getDeepCopy(head) ;
}
