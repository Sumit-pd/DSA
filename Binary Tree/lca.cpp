/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	if(root == NULL){
        return -1 ;
    }
    if(root -> data == x){
        return x ;
    }
    if(root -> data == y){
        return y ;
    }

    int leftCall = lowestCommonAncestor(root -> left , x , y) ;
    int rightCall = lowestCommonAncestor(root -> right , x , y) ;
    if(leftCall == -1){
        return rightCall ;
    }
    else if(rightCall == -1){
        return leftCall ;
    }
    return root -> data ;
    // the very place the data is splited that node is the lca
    
}