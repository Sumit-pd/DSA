#include<bits/stdc++.h>
using namespace std ;
int largestRectangle(vector < int > & heights) {
  int n = heights.size() ;

  vector<int> nextSmaller(n,-1) ;
  stack<int> st ;
  for(int i = n -1 ; i >= 0 ; i-- ){

    while(st.size() && heights[i] <= heights[st.top()] ){
      st.pop() ;
    }

    if(st.empty() ){
      nextSmaller[i] = n ;
    }
    else{
      nextSmaller[i] = st.top() ;
    }
    st.push(i) ;
  }

  stack<int> st2 ;
  vector<int> prevSmaller(n,-1) ;
  for(int i = 0 ; i < n ; i++ ){
    while(st2.size() && heights[st2.top()]  >= heights[i] ){
      st2.pop() ;
    }

    if(st2.empty() ){
      prevSmaller[i] = -1 ;
    }
    else{
      prevSmaller[i] = st2.top() ;
    }

    st2.push(i) ;
  }



  int maxi = 0 ; 
  for(int i = 0 ; i < n ;i++ ){
    int width = nextSmaller[i] - prevSmaller[i] - 1 ;
    maxi = max(maxi,width * heights[i] ) ;
  }

  return maxi ;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	int area = largestRectangle(mat[0]) ;

	for(int i = 1 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++ ){
			if(mat[i][j] != 0){
				mat[i][j] += mat[i-1][j] ;
			}
			else{
				mat[i][j] = 0 ;
			}
		}
		int smallAns = largestRectangle(mat[i]) ;
		area = max(area,smallAns) ;
	}

	return area ;
}