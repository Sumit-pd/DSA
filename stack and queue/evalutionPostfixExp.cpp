#include<bits/stdc++.h>
bool isOperator(char ch){
	if( ch - 'a' >= 0 && ch - 'a' <=25 ){
		return true ;
	}
	else if(ch - '0' >= 0 && ch - '9' <= 9 ){
		return true ;
	}

	else {
		return false ;
	}
}
int evaluatePostfix(string &postFix) {
	stack<long long> st ;
	for(int i = 0 ; i < postFix.size() ; i++ ){
		if(isOperator(postFix[i] ) ){
			st.push(postFix[i] - '0' ) ; 
		}
		else{
			int b = st.top() ;
			st.pop() ;
			int a = st.top() ;
			st.pop() ;
			int val = 0  ;
			switch(postFix[i]){
				case '+' :
					val = a+b ;
					break ;
				case '-':
					val = a - b ;
					break ;
				case '*' :
					val = a * b ;
					break ;
				case '/' :
					val = a / b ;
					break ;
				case '^' :
					val = a ^ b ; 
				default : 
					break ;
			}
			st.push(val) ;
		}
	}
	return st.top() ; 
}