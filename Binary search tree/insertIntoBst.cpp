TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    if(root == NULL ){
        return new TreeNode<int>(val) ;
    }

    if(root -> val < val ){
        root -> right = insertionInBST(root -> right, val) ;
    }
    else{
        root -> left = insertionInBST(root -> left,val) ;
    }

    return root ;
}