void helper(BinaryTreeNode<int> * root , int level , vector<int> &ans ){
    if(root == NULL ){
        return ;
    }
    if(ans.size() == level){
        ans.push_back(root -> data) ;
    }
    helper(root -> right , level + 1 , ans) ;
    helper(root -> left , level + 1 , ans ) ;
}
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans ;
    helper(root , 0 , ans) ;
    return ans ;
}

//bfs


#include<bits/stdc++.h>
vector<int> printRightView(BinaryTreeNode<int>* root) {
    vector<int> ans ;
    if(root == NULL) {
        return ans ;
    }

    queue<BinaryTreeNode<int> * > q ;
    q.push(root) ;
    while(q.size() ){
        int n = q.size() ;
        for(int i = 1 ; i <= n ; i++ ){
            BinaryTreeNode<int> * node = q.front() ;
            q.pop() ;
            if(i == n ){
                ans.push_back(node -> data) ;
            }
            if(node -> left){
                q.push(node -> left) ;
            }
            if(node -> right){
                q.push(node -> right) ;
            }
        }
    }
    return ans ;
