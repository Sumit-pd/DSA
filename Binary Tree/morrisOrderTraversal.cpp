//for inorder
vector<int> morrisTraversal(Node * root){
    if(root == NULL){
        return root ;
    }
    vector<int> ans ;
    Node * cur = root;
    while(cur != NULL ){
        if(cur -> left == NULL){
            ans.push_back(cur -> data) ;
            cur = cur -> right ;
        }
        else{
            Node * temp = root -> left ;
            while(temp -> right != NULL && temp != cur){
                temp = temp -> right ;
            }
            if(temp -> right == NULL){
                temp -> right = cur ;
                cur = cur -> left ;
            }
            else if(temp -> right = cur){
                temp -> right = NULL ;
                ans.push_back(cur -> data) ;
                cur = cur -> right ;
            }
        }
    }
    return ans;
}



//for postorder
vector<int> morrisTraversal(Node * root){
    if(root == NULL){
        return root ;
    }
    vector<int> ans ;
    Node * cur = root;
    while(cur != NULL ){
        if(cur -> left == NULL){
            ans.push_back(cur -> data) ;
            cur = cur -> next ;
        }
        else{
            Node * temp = root -> left ;
            while(temp -> right != NULL && temp != cur){
                temp = temp -> right ;
            }
            if(temp -> right == NULL){
                temp -> right = cur ;
                ans.push_back(cur -> data) ; // here is the change
                cur = cur -> left ;
            }
            else if(temp -> right = cur){
                temp -> right = NULL ;
                cur = cur -> right ;
            }
        }
    }
    return ans;
}

// this uses the concept of threaded binary tree
// time complexity : O(N) + O(N)
// space complexity : O(1)