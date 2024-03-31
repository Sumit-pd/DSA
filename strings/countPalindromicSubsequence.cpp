//brute 
void helper(int i , string str, vector<string> &ans, string output){
	if(i == str.length()){
		if(output == ""){
			return ;
		}
		ans.push_back(output);
		return ;
	}
	output+= str[i] ;
	helper(i+1,str,ans,output) ;
	output.pop_back() ;
	helper(i+1,str,ans,output) ;
}
vector<string> subsequences(string str){
	vector<string> ans ;
	helper(0,str,ans,"");
	return ans ;
}
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
int countPalindromicSubsequences(string &s){
	vector<string> arr = subsequences(s) ;
	int cnt = 0 ;
	for(auto it : arr ){
		if(checkPalindrome(it) == true ){
			cnt++ ;
		}
	}
	return cnt ;
}



//better
//memoization

#include<bits/stdc++.h>
int helper(int i , int j , string s , vector<vector<int>> &dp ){
	if(i > j ){
		return 0 ;
	}
	if(i == j ){
		return 1 ;
	}
	if(dp[i][j] != -1 ){
		return dp[i][j] ;
	}
	if(s[i] == s[j]){
		return dp[i][j] =  1 + helper(i+1,j,s,dp) + helper(i,j-1,s,dp) ;
	}
	else{
		return dp[i][j] = helper(i+1,j,s,dp) + helper(i,j-1,s,dp) - helper(i+1,j-1,s,dp) ;
	}
}



//tabulation

