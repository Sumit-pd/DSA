 
TreeNode * helper(vector<int> &preOrder , int ind , int end  ){
    if(ind == -1  ){
        return NULL ;
    }

    TreeNode * root = new TreeNode(preOrder[ind] ) ;
    int left = -1 ;
    int right = -1 ;
    for(int i = ind + 1  ; i <= end ; i++ ){
        if(preOrder[i] < root -> data ){
            left = i ;
            break ;
        }
    }

     for(int i = left != -1 ? left: ind + 1  ; i <= end ; i++ ){
        if(preOrder[i] > root -> data ){
            right = i ;
            break ;
        }
    }

    root -> left = helper(preOrder,left,right-1) ;
    root -> right = helper(preOrder,right,end) ;
    return root ;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    
    return helper(preOrder,0,preOrder.size() -1 ) ;
    
}