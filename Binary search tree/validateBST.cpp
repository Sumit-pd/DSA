#include <bits/stdc++.h> 
/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode 
    {
      public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() 
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

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