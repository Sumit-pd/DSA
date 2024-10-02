TreeNode<int>* BstToDLL(TreeNode<int>* root,TreeNode<int>* &prev){
    if(root == NULL){
        return NULL ;
    }
    TreeNode<int>* head = BstToDLL(root->left,prev) ; // this will give the same head everytime 
    if(prev == NULL){
        head = root ;
    }
    else{
        prev -> right = root ;
        root -> left = prev ;
    }
    prev = root ;
    BstToDLL(root -> right , prev) ;
    return head ;
}
TreeNode<int>* mergeTwoBstTypeDLL(TreeNode<int>* head1 , TreeNode<int>* head2){
   
    TreeNode<int>* head = NULL ;
    TreeNode<int>* tail = NULL ;
    while(head1 != NULL && head2 != NULL){
        if(head1 -> data < head2 -> data){
            if(head == NULL){
                head = head1;
                tail = head1 ;
                head1 = head1 -> right ;
            }
            else{
                tail -> right = head1 ;
                head1 -> left = tail ;
                tail = tail -> right ;
                head1 = head1 -> right ;
            }
        }
        else{
            if(head == NULL){
                head = head2;
                tail = head2 ;
                head2 = head2 -> right ;
            }
            else{
                tail -> right = head2 ;
                head2 -> left = tail ;
                tail = tail -> right ;
                head2 = head2 -> right ;
            }
        }
    }

    while (head1 != NULL)
    {
        if(head == NULL){
                head = head1;
                tail = head1 ;
                head1 = head1 -> right ;
            }
        else{
            tail -> right = head1 ;
            head1 -> left = tail ;
            tail = tail -> right ;
            head1 = head1 -> right ;
        }
    }
    while (head2 != NULL)
    {
         if(head == NULL){
                head = head2;
                tail = head2 ;
                head2 = head2 -> right ;
            }
        else{
            tail -> right = head2 ;
            head2 -> left = tail ;
            tail = tail -> right ;
            head2 = head2 -> right ;
        }
    }
    
    return head ;
}
int CntNode(TreeNode<int> * head){
    int cnt = 0 ;
    while(head){
        cnt++ ;
        head = head -> right ;
    }
    return cnt ;
}
TreeNode<int> * linkedListToBst(TreeNode<int> * &head,int node){
    if(node <= 0 || head == NULL){
        return NULL ;
    }
    TreeNode<int> * left = linkedListToBst(head -> left ,node/2 ) ;
    TreeNode<int> * root = head ;
    TreeNode<in
}