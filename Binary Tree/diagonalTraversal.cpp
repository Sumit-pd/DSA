#include<bits/stdc++.h>
void helper(TreeNode<int> * root , int line , map< int , vector< TreeNode<int>* > > &mp ){
    if(root == NULL ){
        return ;
    }

    mp[line].push_back(root) ;
    helper(root -> left , line + 1 , mp ) ;
    helper(root -> right , line , mp ) ;
}
vector<int> diagonalTraversal(TreeNode<int> *root) {
    vector<int> ans ; 
    if(root == NULL ) return ans ;

    map< int , vector< TreeNode<int>* > > mp ;
    helper(root,0,mp) ;
    for(auto it : mp ){
        for(auto elem : it.second ){
            ans.push_back(elem -> data );
        }
    }
    return ans ;
}