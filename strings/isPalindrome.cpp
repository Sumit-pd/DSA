#include <bits/stdc++.h> 
bool checkPalindrome(string s)
{
    int n = s.length();
    int low = 0 ; 
    int high = n - 1;

    while(low < high){
        while( (!isalnum(s[low]) || s[low] == ' ') && low < high){ //
            low++;
        }
        while( (!isalnum(s[high]) || s[high] == ' ') && low < high ){
            high--;
        }
        if( tolower(s[low]) != tolower(s[high]) ){
            return false ;
        }
        low++;
        high--;
    }
    return true;
}

