#include <iostream>
#include<vector>
using namespace std ;
/*
- pre : root left right
- inorder : left root right
- post : left right root
*/
int main(){
    vector<int> pre ;
    vector<int> inorder ;
    vector<int> post ;

    stack< pair<TreeNode<int> *,int> > st ;
    TreeNode<int> * root ;
    st.push({root,1}) ;
    while(st.size()){
        auto it = st.top() ;
        st.pop() ;

        if(it.second == 1){
            // this is the first time we visited the node so it should be pre order
            pre.push_back(it.first);
            it.second++ ;
            st.push(it) ;
            if(it.first -> left){
                st.push({it.first -> left , 2}) ;
                
            }
        }
        if(it.second == 2){
            // this is the second time we visted the node so it should be inorder
            inorder.push_back(it.first) ;
            it.second++ ;
            st.push(it) ;
            if (it.first -> right)
            {
                st.push({it.first -> right , 3}) ;
            }
        }
        if(it.third == 3){
            post.push_back(it.first) ;
        }
    }
    return 0 ;
}