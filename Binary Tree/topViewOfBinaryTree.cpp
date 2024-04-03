#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans ; 
    if(root == NULL ){
        return ans ;
    }
    queue<pair<TreeNode<int> *,int> > q ;
    q.push({root,0}) ;
    map<int , TreeNode<int> * > mp ;
    while(q.size() ){
        auto top = q.front() ;
        q.pop() ;
        TreeNode<int> * node = top.first ;
        int level = top.second ;

        if(mp.find(level) == mp.end() ){
            mp[level] = node ;
        }

        if(node -> left){
            q.push({node-> left, level -1}) ;
        }
        if(node -> right){
            q.push({node -> right, level + 1 }) ;
        }
    }

    for(auto it : mp){
        ans.push_back(it.second -> data) ;
    }
    return ans ;
}