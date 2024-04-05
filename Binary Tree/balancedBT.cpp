//naive solution
int height(TreeNode<int> * root){
    if(root == NULL)  return 0 ;

    return 1 + max(height(root -> left ) , height(root -> right ) ) ;
}
bool isBalancedBT(TreeNode<int>* root){
    if(root == NULL ) return true ;

    int lHeight = height(root -> left) ;
    int rHeight = height(root -> right) ;

    int dif = abs(lHeight - rHeight) ;
    if(dif > 1 ){
        return false ;
    }
    return isBalancedBT(root -> left) && isBalancedBT(root -> right) ;
}


//optimized solution

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
pair<int,bool> height(TreeNode<int> * root){
    if(root == NULL)  return {0,true} ;

    pair<int,bool> left = height(root -> left ) ;
    pair<int,bool> right = height(root -> right) ;
    int h = 1 + max(left.first,right.first) ;
    bool ans = abs(left.first - right.first) <= 1 && left.second && right.second ;
    return {h,ans} ;
}
bool isBalancedBT(TreeNode<int>* root)
{
    if(root == NULL ) return true ;

    pair<int,bool> ans = height(root) ;
    return ans.second ;
}