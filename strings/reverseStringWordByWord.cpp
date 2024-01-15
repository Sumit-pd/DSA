#include <iostream>
using namespace std;

string reverseStringWordWise(string input)
{
    string ans = "" ;
    int i = 0 ;
    int n = input.length() ;
    while(i < n){
        while( i < n && input[i] == ' '){
            //checking if the element is an space or not
            i++;
        }
        int j = i + 1 ;
        while(j < n && input[j] != ' ' ){
            j++;
        }
        string smallAns = input.substr(i,j-i);
        if(ans == ""){
            ans = smallAns;
        }
        else{
            ans = smallAns + " " + ans ;
        }
        i = j + 1;
    }
    return ans ;
}

//optimal
#include<bits/stdc++.h>
string reverseOrderWords(string str) {
    //reverse the string 
    // then reverse the individual words
    int n = str.size() ;
    int i = 0 ; // for traversal 
    int l = 0 ; //left pointer for individual word reversal
    int r = 0 ; // right pointer for individual word reversal
    reverse(str.begin(),str.end());
    while(i < n){
    	//this part we are doing it for removal of spaces
        //move i,r and assign i to r till you do not find a space
        while(i< n && str[i] != ' '){
            str[r++] = str[i++];
        }
        if(l<r){
        //reverse  l -> r -1 
            reverse(str.begin()+l,str.begin()+r);
            //this will reverse value till 1 val before r
            str[r++]=' ';
            l = r ;
        }
        i++;
    }
    return str.substr(0,r-1);
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}

