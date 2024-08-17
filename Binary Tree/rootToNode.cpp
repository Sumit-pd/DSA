bool helper(Node * root,vector<int> &ans , int node){
    if(root == NULL){
        return false ;
    }
    ans.push_back(root -> data) ;
    if(root -> data == node ){
        return true ;
    }

    if(helper(root -> left,ans,node) || helper(root -> right,ans,node)){
        return true ;
    }

    ans.pop_back() ;
    return false ;
}

// for root to leaf just change the second base condition