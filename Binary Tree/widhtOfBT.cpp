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
int getMaxWidth(TreeNode<int> *root)
{
    if(root == NULL) return 0 ;
    queue<TreeNode<int>*>  q ;
    q.push(root) ;
    int maxWidth = 0 ;
    while(q.size()){
        int width = q.size() ;

        maxWidth = max(maxWidth,width) ;
        for(int i = 0 ; i < width ; i++ ){
            TreeNode<int> * node = q.front() ;
            q.pop() ;

            if(node -> left ){
                q.push(node -> left) ;
            }
            if(node -> right){
                q.push(node -> right) ;
            }
        }
    }

    return maxWidth ;

}