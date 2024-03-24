#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    int n = s.length() ;
    stack<char> st ;
    for(int i = 0 ; i < n ; i++ ){
        char ch = s[i] ;
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'  || ch == '(' )
        {
            st.push(ch) ;
        }
        else{
            if( ch == ')' ){
                if(st.size() && st.top() == '(' ) return true; 
                while( st.size() && st.top() != '(' ){
                    st.pop() ;
                }
                if(st.size() ) st.pop() ;
                // st.pop() ;
            }
        }
    }
    return false ;
}
//time complexity : O(N) ;
//space complexity : O(N)