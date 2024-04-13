#include <bits/stdc++.h> 
//DFS
bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if(root1 == NULL && root2 == NULL ) return true ;

    if(root1 == NULL || root2 == NULL) return false ;

    if(root1 -> data != root2 -> data ) return false ;

    return areMirror(root1 -> left , root2 -> right) && areMirror(root1 -> right , root2 -> left ) ;

}

//BFS

bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if(root1 == NULL && root2 == NULL ){
        return true ;
    }
    if(root1 == NULL || root2 == NULL ) return false ;

    queue<BinaryTreeNode<int> *> q ;
    q.push(root1) ;
    q.push(root2) ;

    while(q.size()){
        BinaryTreeNode<int> * r1 = q.front() ;
        q.pop() ;
        BinaryTreeNode<int> * r2 = q.front() ;
        q.pop() ;

        if(r1 -> data != r2 -> data ){
            return false ;
        }

        if(r1 -> left != NULL && r2 -> right != NULL){
            q.push(r1 -> left) ;
            q.push(r2 -> right ) ;
        }
        else if(r1 -> left != NULL || r2 -> right != NULL){
            return false ;
        }
         if(r1 -> right != NULL && r2 -> left != NULL){
            q.push(r1 -> right) ;
            q.push(r2 -> left ) ;
        }
        else if(r1 -> right != NULL || r2 -> left != NULL){
            return false ;
        }
    }

    return true ;

}