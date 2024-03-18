#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	int celeb = -1 ;


	 for(int i = 0 ; i < n ; i++){
		 int knowAnyOne = false , everyOneKnows = true ;


		 for(int j = 0 ; j < n ; j++ ){

			 if(i == j ) continue ;
			 if(knows(j,i) == false ){
				 everyOneKnows = false ;
				 break ;
			 }
		 }



		 for(int j = 0 ; j < n ; j++  ){

			 if(i == j ) continue ;

			 if(knows(i,j) == true ) {
				 knowAnyOne = true ;
				 break ;
			 }
		 }



		 if(knowAnyOne == false && everyOneKnows ==true )
		 {
			 celeb = i ;
			 break ;
		 }
	 }

	 return celeb ;
}



#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	stack<int> st ; 
	
	for(int i = 0 ; i < n ; i++ ){
		st.push(i) ;
	}

	while(st.size() > 1 ){
		int a = st.top() ;
		st.pop() ;
		
		int b = st.top() ;
		st.pop() ;

		if(knows(a,b)){
			st.push(b) ;
		}
		else{
			st.push(a) ;
		}
	}


	int elem = st.top() ;
	st.pop() ;
	for(int i = 0 ; i < n ; i++ ){
		if(elem == i ) continue ;
		if(knows(elem,i)){
			elem = -1 ;
			break ;
		}
		if(knows(i,elem) == false){
			elem = -1 ;
			break ;
		}
	}

	return elem ;
}