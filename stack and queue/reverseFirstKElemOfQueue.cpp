#include <bits/stdc++.h> 
queue<int> reverseElements(queue<int> q, int k)
{
    stack<int> st ;
    for(int i = 0 ; i < k ; i++ ){
        st.push(q.front()) ;
        q.pop() ;
    }
    while(st.size()){
        q.push(st.top()) ;
        st.pop() ;
    }

    for(int i = 0 ; i < q.size() - k ; i++ ){
        q.push(q.front()) ;
        q.pop() ;
    }

    return q ;
}
