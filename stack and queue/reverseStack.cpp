void pushAtBottom(stack<int>& st, int x) 
{
    vector<int> arr ; 
    while(st.size()){
        arr.push_back(st.top() ) ;
        st.pop() ;
    }
    st.push(x) ;
    while(arr.size()){
        st.push(arr.back()) ;
        arr.pop_back() ;
    }
}
void reverseStack(stack<int> &stack) {
    if(stack.size() == 0 || stack.size() == 1 ){
        return ;
    }

    int val = stack.top() ;
    stack.pop() ;
    reverseStack(stack) ;
    pushAtBottom(stack,val) ;
}