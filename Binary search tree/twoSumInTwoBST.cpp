class Solution
{
public:
    bool isPresent(Node * root , int x ){
        if(root == NULL) {
            return false ;
        }
        
        if(root -> data == x ){
            return true ;
        }
        else if(root -> data > x ){
            return isPresent(root -> left,x) ;
        }
        else{
            return isPresent(root -> right , x) ;
        }
    }
    void helper(Node * root ,Node * root2, int &cnt, int x ){
        if(root == NULL ){
            return ;
        }
        
        int target = x - root -> data ; 
        if(isPresent(root2,target)){
            cnt++ ;
        }
        helper(root -> left ,root2, cnt , x ) ;
        helper(root -> right ,root2, cnt , x ) ;
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        if(root1 == NULL || root2 == NULL ){
            return 0 ;
        }
        
        int cnt = 0 ;
        helper(root1,root2,cnt,x) ;
        return cnt ;
    }
};
