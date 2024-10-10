class Solution {
public:
    int minSwaps(string s) {
        stack<char> st ;
        int n = s.length() ;
        for(int i = 0 ; i < n ; i++){
            char ch = s[i] ;
            if(ch == '['){
                st.push(ch) ;
            }
            else{
                if(st.empty() || ch == ']'){
                    // both top and s[i] is a ']' so this is not a valid pair 
                    // and we are storing all the invalid pairs in the stack
                    st.push(ch)
                }
                else{
                    st.pop() ;
                }
            }
        }

        int totalBrackets = st.size() ;
        int closingBracket = totalBrackets/2 ;
        return (closingBracket+1)/2 ;
    }
};


class Solution {
public:
    int minSwaps(string s) {
        // stack<char> st ;
        int open = 0 ;
        int closed = 0 ;
        for(int i = 0 ; i < s.length() ; i++ ){
            if(s[i] == '['){
                open++ ;
            }
            else{
                if(open < 1){
                    closed++ ;
                }
                else{
                    open-- ;
                }
            }
        }

        return (closed+1)/2 ;
    }
};