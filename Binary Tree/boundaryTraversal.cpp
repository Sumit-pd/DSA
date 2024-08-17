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
#include<bits/stdc++.h>
void addLeft(TreeNode<int> * root , vector<int> &ans ){
    if(root == NULL ){
        return ;
    }
    if(root -> left == NULL && root -> right == NULL ){
        return ;
    }
    ans.push_back(root -> val) ;
    if(root -> left){
        addLeft(root -> left,ans) ;
    }
    else{
        addLeft(root -> right,ans) ;
    }
}
void addLeaves(TreeNode<int> * root , vector<int> &ans ){
    if(root == NULL){
        return ;
    }
    if(root -> left == NULL && root -> right == NULL ){
        ans.push_back(root -> val) ;
        return;
    } 
    if(root -> left ) addLeaves(root -> left,ans) ;
    if(root -> right) addLeaves(root -> right,ans) ;
}
void addRight(TreeNode<int> * root , vector<int> &ans ){
    if(root == NULL ){
        return ;
    }

    if(root -> left == NULL && root -> right == NULL ){
        return ;
    }
    if(root -> right){
        addRight(root -> right,ans) ;
    }
    else{
        addRight(root -> left , ans) ;
    }
    //printing of right will be after all the element of lower part are printed
    ans.push_back(root -> val) ;
}
vector<int> boundaryTraversal(TreeNode<int> *root)
{
    vector<int> ans ;
    if(root == NULL ){
        return ans;
    }
    ans.push_back(root -> val );
    addLeft(root->left,ans) ;
    addLeaves(root->left,ans) ;
    addLeaves(root -> right,ans);
    addRight(root -> right,ans) ;
    return ans ;
}