#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    if(root == NULL){
        return {} ;
    }
    vector<int> levelOrder ;
    queue<BinaryTreeNode<int> * > q ;
    q.push(root) ;
    while(q.size()){
        BinaryTreeNode<int> * node = q.front() ;
        q.pop() ;
        levelOrder.push_back(node->val) ;
        if(node -> left){
            q.push(node -> left) ;
        }
        if(node -> right ){
            q.push(node -> right) ;
        }
    }
    return levelOrder ;
}