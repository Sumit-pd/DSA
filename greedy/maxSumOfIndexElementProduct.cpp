#include <bits/stdc++.h> 
int mod = 1e9 + 7 ;
int findSum(vector<int> a , int n ){
    int sum = 0 ;
    for(int i = 0 ; i < n ;i++){
        sum = (sum + a[i] * i) % mod ; 
    }
    return sum ;
}
int maximumSum(vector<int> &a, int n) {
    sort(a.begin(),a.end() ) ;
    return findSum(a,n) ;
}