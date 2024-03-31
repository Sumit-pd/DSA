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