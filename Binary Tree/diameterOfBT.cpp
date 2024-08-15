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


// the other way of writing the same code will be as follows

pair<int,int> findDiamenter(TreeNode<int> * root){
    if(root == NULL){
        return {0,0} ;
    }

    pair<int,int> left = findDiamenter(root -> left) ;
    pair<int,int> right = findDiamenter(root -> right) ;

   int diameter = max(left.first,max(right.first, left.second + right.second)) ;
   int height = max(left.second , right.second) + 1 ;
   return {diameter,height} ;
}