#include<bits/stdc++.h>
bool isOperand(char ch){
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

int precedence(char ch ){
	if(ch == '^' ) return 3 ;
	if(ch == '*' || ch == '/' ) return 2 ;
	if(ch == '+' || ch == '-' ) return 1 ;
	if(ch == '(' || ch == ')' ) return 0 ;
}
string infixToPostfix(string arr){
	stack<int> st ;

	string ans = "" ;

	for(int i = 0 ; i < arr.size() ; i++ ){
		if(arr[i] == '(' ){
			st.push(arr[i]) ;
		}
		else if(isOperand(arr[i])){
			ans += arr[i] ;
		}
		else if(arr[i] == ')' ){
			while(st.size() && st.top() != '(' ){
				ans += st.top() ;
				st.pop() ;
			}
			st.pop() ;
		}

		else{
			while(st.size() && precedence(st.top()) >= precedence(arr[i]) ){
				ans += st.top() ;
				st.pop() ;
			}
			st.push(arr[i]) ;
		}
	}

	while(st.size()){
		ans += st.top() ;
		st.pop() ;
	}
	return ans ;
}