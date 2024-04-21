#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
int cntNodes(BinaryTreeNode<int>* root ){
    if(root == NULL ){
        return 0 ;
    }
    return 1 + cntNodes(root -> left) + cntNodes(root -> right) ;
}

bool isCompleteBT(BinaryTreeNode<int> * root , int i , int totalNodes){
    if(root == NULL ){
        return true ;
    }

    if( i >= totalNodes ){
        return false ;
    }

    bool left = isCompleteBT(root -> left , 2 * i + 1 , totalNodes) ;
    bool right = isCompleteBT(root -> right , 2 * i + 2 , totalNodes ) ;
    return left && right ;
}
bool followsProperty(BinaryTreeNode<int> * root ){
    if(root == NULL ){
        return true ;
    }
    if(root -> left == NULL && root -> right == NULL ){
        return true ;
    }

    if(root -> right == NULL ){
        return root -> data >= root -> left -> data ;
    }

    else {
        if(root -> data < root -> left -> data ){
            return false ;
        }
        if(root -> data < root -> right -> data ){
            return false ;
        }
        return followsProperty(root -> left) && followsProperty(root -> right ) ;
    }
    
}
bool isBinaryHeapTree(BinaryTreeNode<int>* root) 
{
    if(root == NULL ){
         return true ;
    }

    if(root -> left == NULL && root -> right == NULL ) {
        return true ;
    }
    int n = cntNodes(root) ;

   if(isCompleteBT(root,0,n) && followsProperty(root) ){
       return true ;
   }
   return false ;
}