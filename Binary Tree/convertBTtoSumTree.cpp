int helper(TreeNode<int> *root ){
    if(!root) return 0 ;

    int oldVal = root -> data ; // the data of the old value of the node ;
    root -> data = helper(root -> left ) + helper(root -> right ) ;

    return root -> data + oldVal ;
}
TreeNode<int> *convertToSumTree(TreeNode<int> *root) {
    if(root == NULL ){
        return root ;
    }

    helper(root) ;
    return root ;
}