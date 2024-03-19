// using vector
#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& st, int x) 
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
    return st ;
}


//using recursion
#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& st, int x) 
{
    if(st.empty()) {
        st.push(x) ;
        return st ;
    }
    int val = st.top() ;
    st.pop() ;
    pushAtBottom(st,x) ;
    st.push(val) ;
    return st ;
}
