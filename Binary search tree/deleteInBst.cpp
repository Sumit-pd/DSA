

BinaryTreeNode<int> * findLeft(BinaryTreeNode<int> * root ){
    if(root -> left == NULL){
        return root ;
    }
    return findLeft(root -> left ) ;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if(root == NULL ){
        return NULL ;
    }

    if(root -> data == key ){

        // case 1 : the root is a leaf node
        if(root -> left == NULL && root -> right == NULL ){
            delete root ;
            return NULL ;
        }
        else if(root -> left == NULL && root -> right != NULL ){
            BinaryTreeNode<int> * temp = root -> right ;
            delete root ;
            return temp ;
        }
        else if(root -> left != NULL && root -> right == NULL ){
            BinaryTreeNode<int> * temp = root ->left ;
            delete root ;
            return temp ;
        }
        else{
            BinaryTreeNode<int> * node = findLeft(root -> right) ;
            root -> data = node -> data ;
            root -> right = deleteNode(root -> right , node -> data ) ;
            return root ;
        }
    }

    else if(root -> data > key ){
        root -> left = deleteNode(root -> left , key ) ;
        return root ;
    }
    else{
        root -> right = deleteNode(root -> right , key ) ;
        return root ;
    }

}
