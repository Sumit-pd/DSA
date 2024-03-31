//recursive
void helper(TreeNode * root ,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    helper(root -> left,ans) ;
    ans.push_back(root -> data) ;
    helper(root -> right,ans) ;
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans ;
    helper(root,ans) ;
    return ans ;

}
//iterative
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> ans ;
    if(root == NULL){
        return ans ;
    }

    stack<TreeNode * > st ;

    TreeNode * Node = root ;

    while(true){
        if(Node != NULL){
            st.push(Node) ;
            Node = Node -> left ;
        }
        else{
            if(st.empty()){
                break ;
            }
            Node = st.top() ;
            st.pop() ;
            ans.push_back(Node -> data);
            Node = Node -> right ;
        }
    }
    return ans ;
}