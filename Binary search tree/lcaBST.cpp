TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	if(root == NULL){
        return NULL ;
    }

    int cur = root -> data ;
    if(cur > p -> data && cur > q -> data){
        return LCAinaBST(root -> left , p , q) ;
    }
    else if(cur > p -> data && cur > q -> data){
        return LCAinaBST(root -> right , p,q) ;
    }
    return root -> data ; // this is the place where the divergen
    
}