#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> * root ){
    if(root -> left == NULL && root -> right == NULL ){
        return true ;
    }

    return false ;
}
int levelLeaf(TreeNode<int> *root) {
    
    vector< pair<TreeNode<int> *,int> > leafNode ;
    queue< pair<TreeNode<int> * , int > > q ;
    q.push({root,0}) ;
    int levelLeaf = -1 ;
    while(q.size()){
        int size  = q.size() ;
        for(int i = 0 ; i < size ; i++ ){
            pair< TreeNode<int> * , int > top = q.front() ;
            q.pop() ;

            TreeNode<int> * node = top.first ;
            int level = top.second ;

            if(isLeaf(node)){
                if(levelLeaf == -1 ){
                    levelLeaf = level ;
                }
                else{
                    if(levelLeaf != level){
                        return false ;
                    }
                }
            }

            else{
                if(node -> left ){
                    q.push({node -> left , level+1} ) ;
                }

                if(node -> right ){
                    q.push({node -> right , level + 1 } ) ; 
                }
            }
        }
    }
    return 1 ;
}





