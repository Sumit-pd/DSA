void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
		return ;
	}
	mirrorBinaryTree(root ->left ); 
	mirrorBinaryTree(root -> right );

	BinaryTreeNode<int> * temp = root -> left ;
	root -> left = root ->right ;
	root -> right = temp ;
}


//bfs way to do so

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
	if(root == NULL ){
		return ;
	}

	queue<BinaryTreeNode<int>*> q ;
	q.push(root) ;
	while(q.size()){
		BinaryTreeNode<int>* front = q.front() ;
		q.pop() ;
		swap(front -> left , front -> right) ;
		if(front -> left){
			q.push(front-> left) ;
		}
		if(front -> right){
			q.push(front -> right) ;
		}
	}
}