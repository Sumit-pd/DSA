/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void convertToBst(TreeNode<int> * root , vector<int> &arr ){
    if(root == NULL ){
        return ;
    }

    convertToBst(root -> left , arr ) ;
    arr.push_back(root -> data ) ;
    convertToBst(root -> right , arr ) ;

}
TreeNode<int> * helper(vector<int> arr ,  int start , int end ){
    if(start > end){
        return NULL ;
    }
    int mid = (start+end ) /2 ;
    TreeNode<int> * root = new TreeNode<int>(arr[mid]) ;
    root -> left = helper(arr,start,mid-1) ;
    root -> right = helper(arr,mid+1,end) ;
    return root ;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    
    vector<int> arr ;
    convertToBst(root,arr) ;

    return helper(arr,0,arr.size()-1 ) ;
    
}
