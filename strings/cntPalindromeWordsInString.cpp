#include <bits/stdc++.h> 
//using the stringstream class to split the string into words
using namespace std;
bool isPalindrome(string str){   
    int low = 0 , high  = str.length() - 1;
    while (low < high){
        if(str[low++] != str[high--]){
            return false;
        }
    }
    return true;
}
string convertToUpper()
int countNumberOfPalindromeWords(string s)
{
	//Your code goes here
   stringstream ss(s) ;
   string word ;
   int cnt = 0 ;
   while(ss >> word ){
    // the ss works as an in put
    // word will be storing the individual words of the string
       transform(word.begin(),word.end(),word.begin(), ::tolower) ;
       if(isPalindrome(word)){
           cnt++ ;
       }
   }
    return cnt;
}


/* A stringstream associates a string object with a stream allowing you 
to read from the string as if it were a stream (like cin).
 To use stringstream, we need to include sstream header file.
 The stringstream class is extremely useful in parsing input.  */