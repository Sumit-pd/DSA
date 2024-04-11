#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int sum(TreeNode<int> * root ){
    if(root == NULL ) return 0 ;

    return sum(root -> left) + sum(root -> right) + root -> val ;
}
bool isSumTree(TreeNode<int> *root)
{
    if(root == NULL ) return true ;
     
    if(root -> left == NULL && root -> right == NULL ) return true ;

    if(root -> val == sum(root -> left) + sum(root -> right) && isSumTree(root -> left ) && isSumTree(root -> right)){
        return true ;
    }

    return false ;
}


pair<int,bool> sum(TreeNode<int> * root ){

    if(root == NULL ) return {0,true} ;

    if(root -> left == NULL && root -> right == NULL ){
        return {root -> val , true } ;
    }

    pair<int,bool> left = sum(root -> left) ;
    pair<int,bool> right =  sum(root -> right) ;

    int sum =  left.first + right.first  ;

    bool isTree = root -> val == (sum) && left.second && right.second ;

    return {sum + root -> val , isTree} ;
}
bool isSumTree(TreeNode<int> *root)
{
    pair<int,bool> ans = sum(root) ;

    return ans.second ;
}
