int helper(TreeNode<int> * root , int &maxi){
    if(root == NULL){
        return 0 ;
    }
    int leftHeight = helper(root -> left , maxi ) ;
    int rightHeight = helper(root -> right , maxi ) ;
    maxi = max(maxi , leftHeight + rightHeight) ;
    return 1 + max(leftHeight,rightHeight) ;
}
int diameterOfBinaryTree(TreeNode<int> *root){
    int maxi = 0 ;
    helper(root,maxi) ;
    return maxi ;
}