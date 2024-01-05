// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std ;
// brute we can use hashmaps
//this is the optimal
bool check(string s1 , string s2 ,string s3){
    if(s1.size() + s2.size() != s3.size()){
        // cout<<"not";
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s3.begin(),s3.end());
    sort(s2.begin(),s2.end());
    int i = 0 ;
    int j = 0 ; 
    int k = 0 ;
    while(k<s3.size()){
       if(i < s1.length() && s1[i] == s3[k]){
           i++;
       }
       else if(j< s2.length() && s2[j] == s3[k]){
           j++;
       }
       else{
           return false ;
       }
       k++;
    }
    return i>= s1.size() && j >= s2.size() ;
}
int main() {
    // Write C++ code here
    string s1 = "sumit";
    string s2 = "prasad";
    string s3 = "sumitprasad";
    cout<<(check(s1,s2,s3));

    return 0;
}