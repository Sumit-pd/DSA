#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void convertToArr(BinaryTreeNode* root, vector<int> &arr ){
	if(root == NULL ){
		return ;
	}
	convertToArr(root -> left,arr ) ;
	arr.push_back(root -> data ) ;
	convertToArr(root -> right,arr ) ;
}
void helper(BinaryTreeNode* root , vector<int> arr , int &i ){
	if(root == NULL ) return ;

	root -> data = arr[i++] ;
	helper(root-> left , arr , i);
	helper(root -> right , arr , i) ;
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	vector<int> arr;
	convertToArr(root,arr) ;
	int i = 0 ;
	helper(root,arr,i) ;
	return root ;

}

