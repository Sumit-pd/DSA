//brute 
//time complexity : O(n2)
//space complexity : O(1)
#include<bits/stdc++.h>
int findNextMin(vector<int> heights , int start , int x ){
  int n = heights.size() ;
  for(int i = start ; i < n ; i++ ){
     if(heights[i] < x ){
       return i ;
     }
  }
  return n  ; // all of the rectangle's height is greater than the x 
}

int findPrevMin(vector<int> heights , int start , int x ){
  int n = heights.size() ;
  for(int i = start ; i >= 0 ; i-- ){
    if(heights[i] < x ){
      return i ; 
    }
  }
  return -1 ; // all of the rectangle's height is greater than the x
}
 int largestRectangle(vector < int > & heights) {
  int maxi = 0 ; 
  int n = heights.size() ;
  for(int i = 0 ; i < n ;i++ ){
  int prevMin = findPrevMin(heights, i , heights[i] ) ;
  int nextMin = findNextMin(heights,i,heights[i] ) ;
  int width = nextMin - prevMin - 1 ;
  maxi = max(maxi, heights[i] * width) ;
  }
  return maxi ;
 }




 #include<bits/stdc++.h>
int largestRectangle(vector < int > & heights) {
  int n = heights.size() ;

  vector<int> nextSmaller(n) ;
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
  vector<int> prevSmaller(n) ;
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


