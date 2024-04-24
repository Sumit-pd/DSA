#include <bits/stdc++.h> 
/***********************************************************

	Following is the Binary Tree node structure:

	class binaryTreeNode{

	public :
		int data ;
		binaryTreeNode* left ;
		binaryTreeNode* right;

		binaryTreeNode(int data)
		{
			this -> data = data;
			this -> left = NULL;
			this -> right = NULL;
		}
	};

*********************************************************/

binaryTreeNode* findMax(binaryTreeNode* root) {
    if(root == NULL || root->right == NULL) {
        return root;
    }
    return findMax(root->right);
}

binaryTreeNode* findMin(binaryTreeNode* root) {
    if(root == NULL || root->left == NULL) {
        return root;
    }
    return findMin(root->left);
}
void helper(binaryTreeNode * root , int key , binaryTreeNode * &pred , binaryTreeNode * &succ  ){
	if(root == NULL ){
		return ;
	}

	if(root -> data == key ){
		if(root->left != NULL) {
            pred = findMax(root->left);
        }
        if(root->right != NULL) {
            succ = findMin(root->right);
        }
        return;
	}
	else if(root -> data > key ){
		succ = root ;
		helper(root -> left , key , pred , succ ) ;
	}
	else{
		pred = root ;
		helper(root -> right , key , pred , succ  ) ;
	}
}
vector<int> findPreSuc(binaryTreeNode *root, int key)
{
	vector<int> ans;
    binaryTreeNode* pred = NULL;
    binaryTreeNode* succ = NULL;

    helper(root, key, pred, succ);

    if(pred != NULL) {
        ans.push_back(pred->data);
    }
    else {
        ans.push_back(-1);
    }

    if(succ != NULL) {
        ans.push_back(succ->data);
    }
    else {
        ans.push_back(-1);
    }

    return ans;

}
