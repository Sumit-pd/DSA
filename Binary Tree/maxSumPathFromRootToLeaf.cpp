#include <bits/stdc++.h> 
/***********************************

    Following is the BinaryTreeNode class structure
    
    class BinaryTreeNode {
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
***********************************/

vector<int> maxSum(BinaryTreeNode<int> *root)
{
    vector<int> ans ;
    if(root == NULL ) return ans ;

    vector<int> leftPath = maxSum(root -> left ) ;
    vector<int> rightPath = maxSum(root -> right ) ;
    leftPath.push_back(root -> data) ;
    rightPath.push_back(root -> data) ;

    int leftSum = 0 ;
    for(auto it : leftPath ){
        leftSum += it ;
    }
    int rightSum = 0 ;
    for(auto it : rightPath){
        rightSum += it ;
    }

    if(root -> right == NULL || (root -> left != NULL && leftSum > rightSum) ) {
        return leftPath ;
    }
    return rightPath ;
}


#include <bits/stdc++.h> 
/***********************************

    Following is the BinaryTreeNode class structure
    
    class BinaryTreeNode {
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
***********************************/
pair<vector<int>,int> helper(BinaryTreeNode<int> * root , int sum ){
    if(root == NULL ){
        vector<int> ans; 
        return {ans,0} ;
    }

    pair< vector<int> , int> left = helper(root -> left , sum ) ;
    pair< vector<int> , int> right = helper(root -> right , sum ) ;
    left.second += root -> data ;
    left.first.push_back(root -> data ) ;

    right.second += root -> data ;
    right.first.push_back(root -> data );

    if(root -> right == NULL || root -> left != NULL && left.second > right.second ){
        return left ;
    }
    return right ;
}
vector<int> maxSum(BinaryTreeNode<int> *root)
{
    auto ans = helper(root,0) ;
    return ans.first ;
}