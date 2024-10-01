#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
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
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

BinaryTreeNode<int> * helper(vector<int> &preorder , int mini , int maxi , int &i){
    if(i >= preorder.size()){
        return NULL ;
    }

    if(preorder[i] < mini || preorder[i] > maxi){
        return NULL ;
    }

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(preorder[i]) ;
    i++ ;
    root -> left = helper(preorder,mini,root -> data , i) ;
    root -> right = helper(preorder,root-> data , maxi , i) ;
    return root ;

}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int i = 0 ;
    return helper(preorder,-1e9,1e9,i) ;
}