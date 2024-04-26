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

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
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
void inorder(BinaryTreeNode<int>* root , vector<int> &inTraversal ){
    if(root == NULL ){
        return ;
    }
    inorder(root -> left , inTraversal ) ;
    inTraversal.push_back(root->data) ;
    inorder(root -> right , inTraversal) ;
}

void helper(BinaryTreeNode<int> * root , vector<int> inTraversal , int &i ){
    if(root == NULL ){
        return ;
    }
    helper(root -> left , inTraversal , i ) ;
    root -> data = inTraversal[i] ;
    i++ ;
    helper(root -> right , inTraversal , i) ;
}
BinaryTreeNode<int>* binaryTreeToBst(BinaryTreeNode<int>* root)
{
    vector<int> inTraversal ;
    inorder(root,inTraversal) ;
    sort(inTraversal.begin(),inTraversal.end() ) ;
    int i = 0 ;
    helper(root,inTraversal,i) ;

    return root ;

}
