#include <bits/stdc++.h> 
string calculateFactorial(int n)
{
    vector<int> ans ;
    ans.push_back(1) ; // consider this as initial value whom we multiply
    for(int i = 2 ; i <= n ;i++){
        int carry = 0 ;
        for(int j = 0 ; j < ans.size() ; j++ ){
            int temp = ans[j] * i + carry ;
            ans[j] = temp % 10; // storing the last digit
            carry = temp /10 ;
        }
        //after the updation of the array there might be a case where carry is present
        while(carry != 0){
            ans.push_back(carry %10) ;
            carry /= 10 ;
        }
    }
    string fact = "" ;
    for(int i = ans.size() -1 ; i >= 0; i-- ){
        fact += to_string(ans[i]);
    }
    return fact ;
}
