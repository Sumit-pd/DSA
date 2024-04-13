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
        return 0 ;
    }
    if(root -> left == NULL && root -> right == NULL ){
        return 1 ;
    }
    return 2 ;
}
void helper( BinaryTreeNode<char> *root , bool &ans , unordered_set<string> &st ){
    if(root == NULL ){
        ans = false ;
        return ;
    }

    int left = checkNode(root -> left) ;
    int right = checkNode(root -> right) ;

    if(left == 0 && right == 0 ){
        return ;
    }
    else if(left == 1 && right == 0){
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
            helper(root -> left , ans , st ) ;
        }
        if(right == 2 ){
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