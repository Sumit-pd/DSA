#include <bits/stdc++.h> 
void deleteMiddle(stack<int>&inputStack, int N){
	
   stack<int> st ; 
   int size = inputStack.size() ;
   
   int mid = N/2 ;

   if(size % 2 == 0 ){
      mid = size / 2 ;
   }
   else{
      mid = (size + 1) / 2 ;
   }

   for(int i = 0 ; i < mid ; i++ ){
      int elem = inputStack.top() ;
      inputStack.pop() ;
      st.push(elem) ;
   }

   inputStack.pop() ;
   while(!st.empty()){
      inputStack.push(st.top() ) ;
      st.pop() ;
   }

}