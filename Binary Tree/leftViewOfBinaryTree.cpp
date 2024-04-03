//recursive
void helper(TreeNode<int> *root , int level , vector<int> &ans ){
    if(root == NULL){
        return ;
    }
    if(ans.size() == level ) {
        ans.push_back(root -> data) ;
    }

    helper(root-> left , level + 1,ans) ;
    helper(root -> right , level +1,ans) ;
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans ;
    helper(root,0,ans) ;
    return ans ;
}




//level order

#include<bits/stdc++.h>
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans ;
    if(root == NULL){
        return ans ;
    }

    queue<TreeNode<int> * > q ;
    q.push(root) ;
    while(q.size()){
        int n = q.size() ;
        for(int i = 0 ; i < n ; i++ ){
            auto cur = q.front() ;
            q.pop();
            if(i == 0 ){
                ans.push_back(cur -> data ) ;
            }
            if(cur -> left ){
                q.push(cur -> left) ;
            }
            if(cur -> right ){
                q.push(cur -> right) ;
            }
        }
    }

    return ans;
}