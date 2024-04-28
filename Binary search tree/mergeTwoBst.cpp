/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
#include<bits/stdc++.h>

void findInorder(TreeNode * root , vector<int> &arr){
    if(root == NULL ){
        return ;
    }
    findInorder(root -> left , arr ) ;
    arr.push_back(root -> data ) ;
    findInorder(root -> right , arr ) ;
}
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0 ;
    int j = 0 ;
    int n = a.size() ;
    int m = b.size() ;
    vector<int> ans ;
    while(i < n && j < m){
        if(a[i] < b[j] ){
            ans.push_back(a[i]);
            i++ ;
        }
        else{
            ans.push_back(b[j]) ;
            j++ ;
        }
    }
    while(i < n ){
        ans.push_back(a[i]);
        i++ ;
    }
    while(j < m ){
        ans.push_back(b[j]) ;
        j++ ;
    }
    return ans ;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> arr1 ; 
    findInorder(root1,arr1) ;
    vector<int> arr2 ;
    findInorder(root2,arr2) ;
    vector<int> mergedBST = sortedArray(arr1,arr2) ;
    return mergedBST;
}