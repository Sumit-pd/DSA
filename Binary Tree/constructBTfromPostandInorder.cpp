/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int> * helper(int inStart , int inEnd , vector<int> &inOrder , int preStart , int preEnd , vector<int> &postOrder , 
unordered_map<int,int> mp  ){
     if(inStart > inEnd  || preStart > preEnd ){
          return NULL ;
     }

     TreeNode<int> * root = new TreeNode<int>(postOrder[preEnd]) ;

     if(inStart == inEnd){
          return root ;
     }
     else{
          int ind = mp[root -> data] ;
          int numOfElem = ind - inStart ;
          root -> left = helper(inStart,ind -1 , inOrder ,preStart,  preStart + numOfElem - 1 , postOrder , mp ) ;
          root -> right = helper(ind + 1 , inEnd , inOrder,preStart + numOfElem , preEnd - 1  , postOrder , mp ) ;
          return root ;
     }
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder)
{
     if(inOrder.size() != postOrder.size()){
          return NULL ;
     }
     unordered_map<int,int> mp ;
     for(int i = 0 ; i < inOrder.size() ; i++ ){
          mp[inOrder[i]] = i ;
     }

     return helper(0,inOrder.size() -1 , inOrder ,0,  postOrder.size() -1 , postOrder, mp ) ;

	
}
