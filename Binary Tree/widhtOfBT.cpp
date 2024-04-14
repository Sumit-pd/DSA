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
//the below will fail for the leetcode problem only works for codestudio
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

int widthOfBinaryTree(TreeNode* root) {
    if(root == NULL){
        return 0 ;
    }        
    queue< pair<TreeNode<int>*,int> > q ;
    q.push({root,0}) ;
    int ans = 0 ;
    while(q.size()){
        int size = q.size();
        int minInd = 0 ;
        int maxInd = 0 ;
        for (int i = 0; i < size ; i++)
        {
            auto front = q.front() ;
            q.pop() ;
            TreeNode* node = front.first ;
            int index = front.second ;
            minInd = min(minInd , index) ;
            maxInd = max(maxInd , index) ;
            if(node -> left ){
                q.push({node -> left ,2*(index - minInd) +1 }) ;
            }
            if(node -> right){
                q.push({node -> right , 2*(index - minInd)+2 }) ;
            }
        }
        ans = max(ans,maxInd - minInd + 1) ;
    }
    return ans ; 
}


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
        return 0 ;
    }        
    queue< pair<TreeNode*,int> >  q ;
    q.push({root,0}) ;
    int ans = 0 ;
    while(q.size()){
        int size = q.size();
        int minInd = 0 ;
        int maxInd = 0 ;
        int levelMin = q.front().second ;
        for (int i = 0; i < size ; i++)
        {
            auto front = q.front() ;
            q.pop() ;
            TreeNode* node = front.first ;
            int index = front.second - levelMin ;
            if(i == 0 ){
                minInd = index ;
            }
            if(i == size -1 ) {
                maxInd = index ;
            }
            if(node -> left ){
                q.push({node -> left ,2*index +1 }) ;
            }
            if(node -> right){
                q.push({node -> right , 2*(index)+2 }) ;
            }
        }
        ans = max(ans,maxInd - minInd + 1) ;
    }
    return ans ; 
    }
};