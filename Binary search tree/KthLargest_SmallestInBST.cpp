void helper(BinaryTreeNode<int> * root , int k , int &cnt , int &ans ){
    if(root == NULL){
        return ;
    }
    helper(root -> left , k , cnt , ans ) ;
    cnt++ ;
    if(cnt == k ){
        ans = root -> data ;
        return ;
    }
    helper(root -> right , k , cnt , ans ) ;
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int ans = -1 ;
    int cnt = 0 ;
    helper(root,k,cnt,ans) ;
    return ans ;
}



/************************************************************/
void helper(TreeNode<int> * root , int k , int &cnt, int &ans){
    if(root == NULL){
        return ;
    }
    helper(root -> right , k , cnt , ans ) ;
    cnt++ ;
    if(k == cnt ){
        ans = root -> data ;
        return ;
    }
    helper(root -> left , k ,cnt , ans ) ;

}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    int ans = -1 ;
    int cnt = 0 ;
    helper(root,k,cnt,ans) ;
    return ans ;
}
