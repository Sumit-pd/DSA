#include <bits/stdc++.h> 
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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    bool leftToRight = false ;
    vector<int> ans ;
    if(root == NULL ){
        return ans ;
    }

    queue<BinaryTreeNode<int> * > q ;
    q.push(root) ;
    while(q.size()){
        int size = q.size() ;
        vector<int> smallAns(size) ;
        for(int i = 0 ; i < size ; i++ ){
            BinaryTreeNode<int> * node = q.front() ;
            q.pop() ;
            smallAns[i] = node -> data ;
            if(node -> left) {
                q.push(node -> left ) ;
            }
            if(node -> right ){
                q.push(node -> right ) ;
            }
        }
        if(leftToRight){
            for(int i = size -1 ; i>= 0 ; i-- ){
                ans.push_back(smallAns[i]) ;
            }
        }
        else{
            for(int i = 0 ; i < size ; i++ ){
                ans.push_back(smallAns[i]) ;
            }
        }
        leftToRight = !leftToRight ;
    } 
    return ans ;
}

