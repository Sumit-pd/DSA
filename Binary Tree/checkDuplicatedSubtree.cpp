/*************************************************************

    Following is the Binary Tree node structure

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
    };

*************************************************************/
#include<bits/stdc++.h>
int checkNode(BinaryTreeNode<char> * root ){
    if(root == NULL ){
        return 0 ; //this indicates the node does not exists
    }
    if(root -> left == NULL && root -> right == NULL ){
        return 1 ; // this indicates the node is a leaf node so it will not count in the answer as leaf node size is one
    }
    return 2 ; // now this is what we are looking for
}
void helper( BinaryTreeNode<char> *root , bool &ans , unordered_set<string> &st ){
    if(root == NULL ){
        ans = false ;
        return ;
    }

    int left = checkNode(root -> left) ;
    int right = checkNode(root -> right) ;

    if(left == 0 && right == 0 ){
        // it is leaf node 
        return ;
    }
    else if(left == 1 && right == 0){
        // the node has one child at the left
        string s = "" ;
        s += root -> data ;
        s += root -> left -> data ;
        s += "$" ;
        if(st.find(s) != st.end()){
            ans = true ;
            return ;
        }
        st.insert(s) ;
    }
    else if(left == 0 && right == 1 ){
        // the node has one child at the right
        string s = "" ;
        s += root -> data ;
        s += "$" ;
        s += root -> right -> data ;
        if(st.find(s) != st.end()){
            ans = true ;
            return ;
        }
        st.insert(s) ;
    }
    else if (left == 1 && right == 1 ){
        // the node has two child 
        string s = "" ;
        s += root -> data ;
        s += root -> left -> data ;
        s += root -> right -> data ;
        if(st.find(s) != st.end()){
            ans = true ;
            return ;
        }
        st.insert(s) ;
    }
    else {
        if(left == 2){
            // the node has more than one child at the left
            helper(root -> left , ans , st ) ;
        }
        if(right == 2 ){
            // the node has more than one child at the right
            helper(root -> right , ans , st ) ;
        }
    }
}
bool similarSubtree(BinaryTreeNode<char> *root)
{	
	unordered_set<string> st ;
    bool ans = false; 
    helper(root,ans,st) ;
    return ans ;
}





#include<bits/stdc++.h>
int checkNodeType(BinaryTreeNode<char> * root){
    if(root == NULL){
        return 0 ;
    }
    if(root -> left == NULL && root -> right == NULL){
        return 1 ;
    }

    return 2 ;
}
bool helper(BinaryTreeNode<char> * root ,unordered_set<string> &st){
    if(root == NULL){
        return false ;
    }

    int left = checkNodeType(root -> left) ;
    int right = checkNodeType(root ->right ) ;
    if(left == 0 && right == 0){
        return false ;
    }
    else if(left == 1 && right == 0){
        string smallString = "" ;
        smallString += root -> data ;
        smallString += root -> left -> data ;
        smallString += "$";
        if(st.find(smallString) != st.end()){
            return true ;
        }
        st.insert(smallString) ;
    }
    else if(left == 0 && right == 1){
        string smallString = "" ;
        smallString += root -> data ;
        smallString += "$" ;
        smallString += root -> right -> data ;
        if(st.find(smallString) != st.end()){
            return true ;
        }
        st.insert(smallString) ;
    }
    else if(left == 1&& right == 1){
        string smallString = "" ;
        smallString += root -> data ;
        smallString += root -> left ->data ;
        smallString += root -> right -> data ;
        if(st.find(smallString) != st.end()){
            return true ;
        }
        st.insert(smallString) ;
    }
    else {
        if(left == 2){
            if(helper(root->left,st) == true){
                return true ;
            }
        }
        if(right == 2){
            if(helper(root->right,st) == true){
                return true ;
            }
        }
    }
    return false ;
}
bool similarSubtree(BinaryTreeNode<char> *root)
{	
    unordered_set<string> st ;
    return helper(root,st) ;
}