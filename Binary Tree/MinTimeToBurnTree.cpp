/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
BinaryTreeNode<int>* createMapAndReturnTarget(BinaryTreeNode<int>* root , int target , unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mp)
{
    mp[root] = NULL ;
    BinaryTreeNode<int>* res = NULL ;
    queue<BinaryTreeNode<int>*> q ;
    q.push(root) ;
    while(q.size()){
        BinaryTreeNode<int>* node = q.front() ;
        q.pop() ;
        if(node -> data == target){
            res = node ;
        }

        if(node -> left){
            mp[node -> left] = node ;
            q.push(node -> left);
        }
        if(node -> right){
            mp[node -> right] = node ;
            q.push(node -> right) ;
        }
    }
    return res ;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mp ;
    BinaryTreeNode<int> * targetNode = createMapAndReturnTarget(root,start,mp) ;

    queue<BinaryTreeNode<int> *> q ;
    q.push(targetNode) ;

    unordered_map<BinaryTreeNode<int> * , bool> visited;
    visited[targetNode] = true ;

    int cnt = 0 ;
    while(q.size()){
        int size = q.size() ;


        bool flag = false ;  
        // this will take care if there is an insertion of some element in the queue which indicates there will be some element to burn
        for(int i = 0 ; i < size ; i++ ){
            BinaryTreeNode<int> * node = q.front() ;
            q.pop() ;
            if(node -> left && !visited[node -> left]){
                visited[node -> left] = true ;
                flag = true ;
                q.push(node -> left); 
            }
            if(node -> right && !visited[node -> right]){
                flag = true ;
                visited[node -> right] = true ;
                q.push(node -> right) ;
            }
            if(mp[node] && !visited[mp[node]]){
                flag = true ;
                visited[mp[node]] = true ;
                q.push(mp[node]) ;
            }
        }

        if(flag == true){
            cnt++ ;
        }
    }

    return cnt ;
    
}
