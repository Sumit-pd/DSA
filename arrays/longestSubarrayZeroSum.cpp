int LongestSubsetWithZeroSum(vector < int > arr) {
 
  int n = arr.size() ;
  int ans = 0 ;
  for(int i = 0 ; i < n ; i++ ){
      int sum = 0 ;
      int count = 0 ;
      for(int j = i ; j < n ; j++ ){
          sum += arr[j] ;
          count++ ;
          if(sum == 0 ){
            ans = max(ans , count ) ;
          }
      }
  }
  return ans ;
}


#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {
 
  int n = arr.size() ;
  int ans = 0 ;
  unordered_map<int,int> mp ;
  int sum = 0 ;
  for(int i = 0 ; i < n ; i++ ){
      sum += arr[i] ;
      if(sum == 0){
        ans = i + 1 ;
      }
      else{
        if(mp.find(sum) != mp.end() ){
          ans = max((i - mp[sum]) , ans ) ;
        }
        else{
          mp[sum] = i ;
        }
      }
  }
  return ans ;

}

