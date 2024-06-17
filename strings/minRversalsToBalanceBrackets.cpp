#include <bits/stdc++.h> 
//here the reversals mean reverse str[i] to opposite 
// in the swapping question we needed to swap among the chars of the string.
int findMinimumCost(string str) {
  int n = str.length() ;
  if(n%2!= 0){
    return -1 ;
  }
  int open = 0 ; 
  int close = 0 ;
  for(char it : str){
    // removing the valid pairs
    // add 
    if(it == '{'){
      open++;
    }
    else {
      if(open == 0 ){
        close++;
      }
      else{
        open--;
      }
    }
  }
  int rev = (int) ceil(open/2.0) + ceil(close/2.0);
  return rev;
}
