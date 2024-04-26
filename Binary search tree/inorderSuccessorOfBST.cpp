#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *next;

	    TreeNode(T data)
	    {
		    this->data = data;
		    left = NULL;
		    right = NULL;
		    next=NULL;
	    }
    };

************************************************************/
void helper(TreeNode<int> * root , TreeNode<int> * &prev ){
    if(root == NULL ){
        return ;
    }

    helper(root -> left , prev ) ;
    if(prev != NULL ){
        prev -> next = root ;
    }
    prev = root ;
    helper(root -> right,prev ) ;
}
void inorderSuccessor(TreeNode<int> *root)
{
    TreeNode<int> * prev = NULL ;
	helper(root, prev ) ;
    if(prev){
        prev -> next = NULL ;
    }
}