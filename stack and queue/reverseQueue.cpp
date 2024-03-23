#include <bits/stdc++.h> 
void reverse(queue < int > & q) {
    stack<int> st ;
    while(q.size()){
        st.push(q.front()) ;
        q.pop() ;
    }

    while(st.size()){
        q.push(st.top()) ;
        st.pop() ;
    }
}



#include <bits/stdc++.h> 
void reverse(queue < int > & q) {
    if(q.size() == 0 ){
        return ;
    }
    int val = q.front() ;
    q.pop() ;
    reverse(q) ;
    q.push(val) ;
}