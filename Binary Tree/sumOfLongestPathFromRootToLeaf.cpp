class Solution
{
public:
    void helper(Node * root , int len , int sum , pair<int,int> &ans){
        if(root == NULL ) return ;
        if(root -> left == NULL && root -> right == NULL ){
            if(len > ans.first ){
                ans = {len,sum} ;
            }
            else if(len == ans.first ){
                ans.second = max(sum,ans.second) ;
            }
            return ;
        }
        if(root -> left ){
            helper(root -> left , len + 1 , sum + root -> left -> data , ans ) ;
        }
        if(root -> right){
            helper(root -> right , len + 1 , sum + root -> right -> data , ans ) ;
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root == NULL) return 0 ;
        pair<int,int> ans = {0,0} ; 
        helper(root, 1 , root -> data , ans ) ;
        return ans.second ;
        
    }
};