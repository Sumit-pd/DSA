
int findMax(BinaryTreeNode<int> * root ){
    if(root == NULL ){
        return  INT_MIN ;
    }
    int left = findMax(root -> left) ;
    int right = findMax(root -> right ) ;
    return max( left , max( right , root -> data ) ) ;
}

int findMin(BinaryTreeNode<int> * root ){
    if(root == NULL ){
        return INT_MAX ;
    }
    int left = findMin(root -> left) ;
    int right = findMin(root -> right ) ;
    return min( left , min( right , root -> data ) ) ;

}
bool validateBST(BinaryTreeNode<int>* root) 
{
    if(root == NULL ){
        return true ;
    }
    
    if(root -> left && root -> left -> data >=  root -> data ){
        return false ;
    }
    if(root -> right && root -> right -> data <= root -> data ){
        return false ;
    }
    int leftMax = findMax(root -> left ) ;
    if(leftMax >= root -> data ){
        return false ;
    }
    int rightMax = findMin(root -> right ) ;
    if(rightMax <= root -> data ){
        return false ;
    }

    if(validateBST(root -> left ) == false ){
        return false ;
    }
    if( validateBST(root -> right) == false ){
        return false ;
    }

    return true ;
}

/*********************************8*/


bool helper(BinaryTreeNode<int> * root , int min , int max ){
    if(root == NULL ){
        return true ;
    }


    if ((root->data <= min) || (root->data >= max)) 
    {
        return false;
    }

    bool left = helper(root -> left , min , root -> data ) ;
    bool right = helper(root -> right , root -> data , max ) ;

    return left & right ;
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    return helper(root , INT_MIN , INT_MAX) ;
}


TreeNode *solve(vector<int> &preOrder, int left, int right, int &index){

 

    if(index >= preOrder.size())

       return NULL;

 

    if(preOrder[index] > left && preOrder[index] < right){

 

        // Create a node

        TreeNode *node = new TreeNode(preOrder[index++]);

        if(index < preOrder.size()) node->left = solve(preOrder, left, node->data, index);

        if(index < preOrder.size()) node->right = solve(preOrder, node->data, right, index);

 

        return node;

 

    }

 

    return NULL;

 

}

 

TreeNode *preOrderTree(vector<int> &preOrder){

    

    int index = 0;

 

    return solve(preOrder, INT_MIN, INT_MAX, index);

    

}